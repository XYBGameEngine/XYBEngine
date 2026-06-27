#ifndef EDITORLAUNCHER_H
#define EDITORLAUNCHER_H

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