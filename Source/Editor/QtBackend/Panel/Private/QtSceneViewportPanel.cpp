#include "QtSceneViewportPanel.h"

#include "ui_QtSceneViewportPanel.h"

#ifdef _WIN32
#include "DX12SceneViewport.h"
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
        m_viewportWindow = new DX12SceneViewport(this);
        m_viewportWindow->setFocusPolicy(Qt::StrongFocus);
        ui->UI_ViewportLayout->layout()->addWidget(m_viewportWindow);
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
