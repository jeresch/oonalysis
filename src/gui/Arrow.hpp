#ifndef GUI_ARROW_HPP
#define GUI_ARROW_HPP

#include <QWidget>

namespace oonalysis::gui {

class Arrow : public QWidget {
public:
    Arrow(QWidget* pointer, QWidget* pointee, QWidget* parent = nullptr);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QWidget* pointer;
    QWidget* pointee;
};

} // namespace oonalysis::gui

#endif