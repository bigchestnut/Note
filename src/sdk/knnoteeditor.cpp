#include "knnoteeditor.h"

KNNoteEditor::KNNoteEditor(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化窗口大小和样式表
    this->setGeometry(400,100,600,300);
    this->setStyleSheet("background-color: rgb(35,35,35);""color:white;");

    //初始化textEdit
    //创建textedit
    textEdit = new QTextEdit(this);
    //设置字体大小 粗细 内容
    textEdit->setFontPointSize(20);
    textEdit->selectAll();

    //设置主widget
    setCentralWidget(textEdit);

    //创建字体工具条
    QToolBar *fontToolBar = addToolBar("Font");

    //字体
    fontLabel = new QLabel("Font:");
    fontBox = new QFontComboBox();
    fontBox->setFontFilters(QFontComboBox::ScalableFonts);

    fontToolBar->addWidget(fontLabel);
    fontToolBar->addWidget(fontBox);

    //字号
    fontSizeLabel = new QLabel("Font size:");
    fontSizeBox = new QComboBox();

    fontToolBar->addWidget(fontSizeLabel);
    fontToolBar->addWidget(fontSizeBox);

    QFontDatabase fontDatabase;
    foreach(int nSize,fontDatabase.standardSizes())
        fontSizeBox->addItem(QString::number(nSize));

    fontToolBar->addSeparator();

    //加粗
    fontBoldButtton = new QToolButton();
    fontBoldButtton->setIcon(QIcon(":/new/icon/images/icon/bold.png"));
    fontBoldButtton->setCheckable(true);

    fontToolBar->addWidget(fontBoldButtton);

    //斜体
    fontItalicButton = new QToolButton();
    fontItalicButton->setIcon(QIcon(":/new/icon/images/icon/italic.png"));
    fontItalicButton->setCheckable(true);

    fontToolBar->addWidget(fontItalicButton);

    //下划线
    fontUnderButton = new QToolButton();
    fontUnderButton->setIcon(QIcon(":/new/icon/images/icon/underline.png"));
    fontUnderButton->setCheckable(true);

    fontToolBar->addWidget(fontUnderButton);

    //颜色
    fontColorButton = new QToolButton();
    fontColorButton->setIcon(QIcon(":/new/icon/images/icon/color.png"));
    fontColorButton->setCheckable(true);

    fontToolBar->addWidget(fontColorButton);

    connect(fontBox,SIGNAL(activated(QString)),this,SLOT(slotFont(QString)));
    connect(fontSizeBox,SIGNAL(activated(QString)),this,SLOT(slotSize(QString)));
    connect(fontBoldButtton,SIGNAL(clicked(bool)),this,SLOT(slotBold()));
    connect(fontItalicButton,SIGNAL(clicked(bool)),this,SLOT(slotItalic()));
    connect(fontUnderButton,SIGNAL(clicked(bool)),this,SLOT(slotUnder()));
    connect(fontColorButton,SIGNAL(clicked(bool)),this,SLOT(slotColor()));
    connect(textEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),
            this,SLOT(slotCurrentFormatChanged(QTextCharFormat)));

}

void KNNoteEditor::slotFont(QString f)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(f);
    mergeFormat(fmt);
}

void KNNoteEditor::slotSize(QString num)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(num.toFloat());
    mergeFormat(fmt);
}

void KNNoteEditor::slotBold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(fontBoldButtton->isChecked()? QFont::Bold : QFont::Normal);
    mergeFormat(fmt);
}

void KNNoteEditor::slotItalic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(fontItalicButton->isChecked());
    mergeFormat(fmt);
}

void KNNoteEditor::slotUnder()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(fontUnderButton->isChecked());
    mergeFormat(fmt);
}

void KNNoteEditor::slotColor()
{
    QColor color = QColorDialog::getColor(Qt::white,this);

    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        mergeFormat(fmt);
    }
}

void KNNoteEditor::slotCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontBox->setCurrentIndex(fontBox->findText(fmt.fontFamily()));
    fontSizeBox->setCurrentIndex(fontSizeBox->findText(QString::number(fmt.fontPointSize())));
    fontBoldButtton->setChecked(fmt.font().bold());
    fontItalicButton->setChecked(fmt.font().italic());
    fontUnderButton->setChecked(fmt.font().underline());
}

void KNNoteEditor::setData(int column, QString value)
{
    textEdit->setText(value);
}

QString KNNoteEditor::getData(int column)
{
    return textEdit->toPlainText();
}

void KNNoteEditor::mergeFormat(QTextCharFormat fmt)
{
    QTextCursor cursor = textEdit->textCursor();

    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
    textEdit->mergeCurrentCharFormat(fmt);
}






