#include "gui/mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])  {
    QApplication::setApplicationName("oonalysis");
    QApplication::setOrganizationName("Jeremy Schroeder");

    QApplication oonalysisApp(argc, argv);

    auto main_window = oonalysis::gui::MainWindow::get_instance();
    main_window->show();

    return oonalysisApp.exec();
}
