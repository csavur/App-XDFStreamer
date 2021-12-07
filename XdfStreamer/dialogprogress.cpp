#include "dialogprogress.h"
#include "ui_dialogprogress.h"
#include "xdfstreamer.h"
#include <iostream>
#include <QLabel>
#include <QGridLayout>

DialogProgress::DialogProgress(const QMap<int, std::string> streams, QWidget *parent) : QDialog(parent),
    ui(new Ui::DialogProgress)
{
    ui->setupUi(this);

    QGridLayout *grid = new QGridLayout(ui->centralWidget);
    QMapIterator<int, std::string> it(streams);
    int row = 0;
    while (it.hasNext()) {
        it.next();

        QLabel *label = new QLabel(this);
        label->setText(QString("Stream %1 :").arg(QString::fromStdString(it.value())));

        grid->addWidget(label, row, 0);

        QProgressBar * prog = new QProgressBar(this);
        prog->setMinimum(0);
        prog->setMaximum(100);
        prog->setValue(0);
        grid->addWidget(prog, row, 1);

        m_progressbars.insert(it.key(), prog);
        ++row;
    }
}

DialogProgress::~DialogProgress()
{
    delete ui;
}

void DialogProgress::updateProgress(int stream_id, int percentage)
{
    if(m_progressbars.contains(stream_id)) {
        m_progressbars[stream_id]->setValue(percentage);
    }

    if(percentage == 100) {
        this->close();
    }

}
