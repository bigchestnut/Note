#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QFontComboBox>
#include <QComboBox>
#include <QToolButton>
#include <QToolBar>
#include <QFontDatabase>
#include <QColorDialog>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QString>
class KNNoteEditor : public QMainWindow
{
    Q_OBJECT
public:
    KNNoteEditor(QWidget *parent = 0);
    void setData(int column,QString value);
    QString getData(int column);
protected slots:
    void slotFont(QString f);
    void slotSize(QString num);
    void slotBold();
    void slotItalic();
    void slotUnder();
    void slotColor();
    //当光标所在处的字符格式发生变化时，更新工具栏各个格式的显示
    void slotCurrentFormatChanged(const QTextCharFormat & fmt);

signals:
private:

    void mergeFormat(QTextCharFormat fmt);

    QLabel *fontLabel;
    QLabel *fontSizeLabel;

    QFontComboBox *fontBox;
    QComboBox *fontSizeBox;

    QToolButton *fontBoldButtton;
    QToolButton *fontItalicButton;
    QToolButton *fontUnderButton;
    QToolButton *fontColorButton;

    QTextEdit *textEdit;

public slots:
};

#endif // NOTEEDITOR_H
