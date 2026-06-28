#include "QtSceneViewportPanel.h"

#include "ui_QtSceneViewportPanel.h"

#ifdef _WIN32
#include "DX12ViewportWindow.h"
#include <QVBoxLayout>
#endif

namespace XYBEngine
{
    namespace EditorPanelIds
    {
        inline constexpr const char* SceneViewport = "SceneViewport";
    }

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

        m_viewportWindow = new DX12ViewportWindow();
        m_viewportContainer = QWidget::createWindowContainer(m_viewportWindow, this);
        m_viewportContainer->setMinimumSize(320, 240);
        m_viewportContainer->setFocusPolicy(Qt::StrongFocus);
        layout->addWidget(m_viewportContainer);
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
