#include "QtSceneViewportPanel.h"

#include "ui_QtSceneViewportPanel.h"

#ifdef _WIN32
#include "DX12TriangleRenderer.h"
#include <QPaintEngine>
#include <QResizeEvent>
#include <QShowEvent>
#include <QTimer>
#include <QVBoxLayout>
#endif

namespace XYBEngine
{
    namespace EditorPanelIds
    {
        inline constexpr const char* SceneViewport = "SceneViewport";
    }

#ifdef _WIN32
    class QtSceneViewportPanel::DX12ViewportWidget : public QWidget
    {
    public:
        explicit DX12ViewportWidget(QWidget* parent = nullptr)
            : QWidget(parent)
        {
            setAttribute(Qt::WA_NativeWindow);
            setAttribute(Qt::WA_NoSystemBackground);
            setFocusPolicy(Qt::StrongFocus);
            setMinimumSize(320, 240);

            m_renderTimer.setTimerType(Qt::PreciseTimer);

            connect(&m_renderTimer, &QTimer::timeout, this, [this]() {
                if (m_renderer.IsInitialized())
                {
                    m_renderer.Render();
                }
            });
        }

        ~DX12ViewportWidget() override
        {
            m_renderTimer.stop();
            m_renderer.Shutdown();
        }

        QPaintEngine* paintEngine() const override
        {
            return nullptr;
        }

    protected:
        void showEvent(QShowEvent* event) override
        {
            QWidget::showEvent(event);

            if (m_renderer.IsInitialized())
            {
                return;
            }

            QTimer::singleShot(0, this, [this]() {
                TryInitializeRenderer();
            });
        }

        void resizeEvent(QResizeEvent* event) override
        {
            QWidget::resizeEvent(event);

            if (!m_renderer.IsInitialized())
            {
                TryInitializeRenderer();
                return;
            }

            if (m_renderer.IsInitialized())
            {
                m_renderer.Resize(static_cast<uint32>(event->size().width()), static_cast<uint32>(event->size().height()));
            }
        }

    private:
        void TryInitializeRenderer()
        {
            if (m_renderer.IsInitialized())
            {
                return;
            }

            const uint32 w = static_cast<uint32>(QWidget::width());
            const uint32 h = static_cast<uint32>(QWidget::height());
            if (w == 0 || h == 0)
            {
                return;
            }

            const auto hwnd = reinterpret_cast<HWND>(winId());
            if (m_renderer.Initialize(hwnd, w, h))
            {
                m_renderTimer.start(16);
            }
            else
            {
                XYB_LOG_ERROR("Failed to initialize DX12 viewport renderer");
            }
        }
        DX12TriangleRenderer m_renderer;
        QTimer m_renderTimer;
    };
#endif

    static SharedPtr<IEditorPanel> CreateSceneViewportPanel()
    {
        return MakeShared<QtSceneViewportPanel>();
    }

    void QtSceneViewportPanelResiter()
    {
        EditorPanelRegister::GetInstance().Register(EditorPanelIds::SceneViewport, CreateSceneViewportPanel);
    }

    QtSceneViewportPanel::QtSceneViewportPanel(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::QtSceneViewportPanel)
    {
        ui->setupUi(this);

#ifdef _WIN32
        auto* layout = new QVBoxLayout(this);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);

        m_viewportWidget = new DX12ViewportWidget(this);
        layout->addWidget(m_viewportWidget);
#else
        XYB_LOG_WARNING("DX12 viewport rendering is only supported on Windows");
#endif
    }

    QtSceneViewportPanel::~QtSceneViewportPanel()
    {
        delete ui;
    }

    const char* QtSceneViewportPanel::GetPanelId() const
    {
        return EditorPanelIds::SceneViewport;
    }

    void* QtSceneViewportPanel::GetNativeView() const
    {
        return const_cast<QWidget*>(static_cast<const QWidget*>(this));
    }

    void QtSceneViewportPanel::Show()
    {
        this->show();
    }

    void QtSceneViewportPanel::Hide()
    {
        this->hide();
    }

    void QtSceneViewportPanel::Close()
    {
        this->close();
    }
}
