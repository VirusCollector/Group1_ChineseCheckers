#ifndef TEMP_PLAYER_H
#define TEMP_PLAYER_H

#include <QWidget>

namespace Ui {
class temp_player;
}

class temp_player : public QWidget
{
    Q_OBJECT

public:
    explicit temp_player(QWidget *parent = nullptr);
    ~temp_player();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

signals:
    void sendnum(int k);

private:
    Ui::temp_player *ui;
};

#endif // TEMP_PLAYER_H
