#ifndef DIALOGPROGRESS_H
#define DIALOGPROGRESS_H

#include <QDialog>
#include <QProgressBar>
#include <QMap>

namespace Ui {
class DialogProgress;
}

class DialogProgress : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProgress(const QMap<int, std::string >streams, QWidget *parent = nullptr);
    ~DialogProgress();

public slots:
    void updateProgress(int stream_id, int percentage);

private:
    Ui::DialogProgress *ui;
    QMap<int, QProgressBar *> m_progressbars;

};

#endif // DIALOGPROGRESS_H
