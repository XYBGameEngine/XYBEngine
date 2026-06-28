#include "QtSceneViewportPanel.h"
#include "ui_QtSceneViewportPanel.h"

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