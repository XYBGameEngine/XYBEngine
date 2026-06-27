#ifndef EDITORLAUNCHER_H
#define EDITORLAUNCHER_H

#include "Core.h"
#include "CreateEditorFactory.h"
#include "IEditorApplication.h"
#include "IEditorWindow.h"

namespace XYBEngine
{
    class EditorLauncher
    {
    public:
        EditorLauncher() = default;

        void Run(int argc, char* argv[]);
    };
}
#endif // EDITORLAUNCHER_H