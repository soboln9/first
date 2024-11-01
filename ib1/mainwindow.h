#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QRandomGenerator>
#include <bitset>
#include <QFile>
#include <QVector>
#include <vector>
#include <string>
#include <QTextStream>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bitset<64> IP(bitset<64>& block);
    bitset<48> Expand(bitset<32>& halfblock);
    bitset<32> P(bitset<32>& input);
    bitset<32> S(bitset<48>& afterxor);
    QVector<bitset<48>> generate_round_keys(bitset<64>& key);
    bitset<64> IP_1(bitset<64>& block);
    QVector<bitset<64>> stringiinbinary(QString& input);
    bitset<64> keyiinbinary(QString& key);

    bitset<64> encdes(bitset<64>& sourcetxt, bitset<64>& key);
    bitset<64> decdes(bitset<64>& sourcetxt, bitset<64>& key);

    ~MainWindow();
private slots:
    void generickey();
    void encslot();
    void decslot();

    void loadopslot();
    void loadclslot();
    void loadkeyslot();
    void unloadopslot();
    void unloadclslot();
    void unloadkeyslot();


private:
    Ui::MainWindow *ui;
    QPushButton* genkey;
    QPushButton* encrip;
    QPushButton* decrip;


    QPushButton* loadop;
    QPushButton* loadcl;
    QPushButton* loadkey;
    QPushButton* unloadop;
    QPushButton* unloadcl;
    QPushButton* unloadkey;

    QVector<bitset<64>> ks;
    QVector<bitset<64>> o;

};
#endif // MAINWINDOW_H
