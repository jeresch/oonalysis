#ifndef GUI_MAINWINDOW_HPP
#define GUI_MAINWINDOW_HPP

#include <QMainWindow>
#include <QTreeWidget>
#include <QLabel>
#include <QScrollArea>
#include <string>
#include <graphviz/cgraph.h>
#include <memory>
#include "FileTree.h"
#include "GraphDisplayRegion.hpp"
#include "OOProject.hpp"

namespace oonalysis::gui {

class MainWindow : public QMainWindow {

public:
    MainWindow();

    static MainWindow* get_instance();

    std::vector<std::string> get_compilation_arguments();

    void setProject(std::shared_ptr<OOProject> proj) { project = proj; }
    void reloadProject();

private:
    void create_menu_bar();

    void onNewProject();
    void onOpenProject();
    void on_parse();
    void onShowInclusions();

    FileTree *file_tree;
    GraphDisplayRegion* graph_display_region;

    std::shared_ptr<OOProject> project;

    static MainWindow* instance;

}; // class MainWindow

} // namespace oonalysis::gui

#endif // GUI_MAINWINDOW_HPP