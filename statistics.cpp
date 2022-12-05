#include "statistics.h"
#include "ui_statistics.h"
#include "equip.h"
#include <QtSql/qsqlquery.h>
#include "QtSql/qsqlquery.h"

QT_CHARTS_USE_NAMESPACE

    statistics::statistics(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::statistics)
    {
        ui->setupUi(this);
    }

    statistics::~statistics()
    {
        delete ui;
    }
/*

//bar chart
void statistics::choix_bar()
    {
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM EQUIPEMENTS");
    q1.exec();

    q2.prepare("SELECT * FROM EQUIPEMENTS WHERE LOCAL='salle1'");
    q2.exec();

    q3.prepare("SELECT * FROM EQUIPEMENTS WHERE LOCAL='salle2'");
    q3.exec();

    q4.prepare("SELECT * FROM EQUIPEMENTS WHERE LOCAL='parking'");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;
  // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("salle1");
            QBarSet *set1 = new QBarSet("salle2");
            QBarSet *set2 = new QBarSet("parking");

            // Assign values for each bar
            *set0 << 33;//c1;
            *set1 << 33; //c2;
            *set2 << 33;// c3;



            // Add all sets of data to the chart as a whole
            // 1. Bar Chart
            QBarSeries *series = new QBarSeries();

            // 2. Stacked bar chart
            series->append(set0);
            series->append(set1);
            series->append(set2);


            // Used to define the bar chart to display, title
            // legend,
            QChart *chart = new QChart();

            // Add the chart
            chart->addSeries(series);
            chart->setTitle("types:");
            chart->setAnimationOptions(QChart::AllAnimations);

            // Adds categories to the axes
           // QBarCategoryAxis *axis = new QBarCategoryAxis();



            // 1. Bar chart
           // chart->setAxisX(axis, series);

            // Used to change the palette
            QPalette pal = qApp->palette();

            // Change the color around the chart widget and text
            pal.setColor(QPalette::Window, QRgb(0xffffff));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));

            // Apply palette changes to the application
            qApp->setPalette(pal);
    QChartView *chartView = new QChartView(chart);

    // Used to display the chart

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);
    ui->verticalLayout->addWidget(chartView);
    chartView->show();
    }


    //pie chart
 void statistics::choix_pie()
        {
        QSqlQuery q1,q2,q3,q4;
        qreal tot=0,c1=0,c2=0,c3=0;

        q1.prepare("SELECT * FROM EQUIPEMENTS");
        q1.exec();

        q2.prepare("SELECT * FROM EQUIPEMENTS WHERE LOCAL='salle1'");
        q2.exec();

        q3.prepare("SELECT * FROM EQUIPEMENTS WHERE LOCAL='salle2'");
        q3.exec();

        q4.prepare("SELECT * FROM EQUIPEMENTS WHERE LOCAL='parking' ");
        q4.exec();

        while (q1.next()){tot++;}
        while (q2.next()){c1++;}
        while (q3.next()){c2++;}
        while (q4.next()){c3++;}

        c1=c1/tot;
        c2=c2/tot;
        c3=c3/tot;

        // Define slices and percentage of whole they take up
        QPieSeries *series = new QPieSeries();
        series->append("choix 1",c1);
        series->append("choix 2",c2);
        series->append("choix 3",c3);




        // Create the chart widget
        QChart *chart = new QChart();

        // Add data to chart with title and show legend
        chart->addSeries(series);
        chart->legend()->show();


        // Used to display the chart
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setMinimumSize(400,400);
        ui->verticalLayout->addWidget(chartView);
        ui->verticalLayout_2->addWidget(chartView);
        chartView->show();
        }*/


    void statistics::choix_bar()
    {
        int total;
        int salle_2 ;
        int salle_1=0 ;
        int salle_3 ;
        int parking=0 ;
        QString Salle_2;
        QString Salle_1;
        QString Salle_3;
        QString Parking;
        QSqlQuery q;
        q.prepare("SELECT COUNT(ID_EQUIP) FROM EQUIPEMENTS where LOCAL ='salle1' ");
                q.exec();
                q.first();
                salle_2=(q.value(0).toInt());
        q.prepare("SELECT COUNT(ID_EQUIP) FROM EQUIPEMENTS where LOCAL ='salle2' ");
                q.exec();
                q.first();
                salle_1=(q.value(0).toInt());
                q.prepare("SELECT COUNT(ID_EQUIP) FROM EQUIPEMENTS where LOCAL ='salle2' ");
                        q.exec();
                        q.first();
                        salle_3=(q.value(0).toInt());
                        q.prepare("SELECT COUNT(ID_EQUIP) FROM EQUIPEMENTS where LOCAL ='salle2' ");
                                q.exec();
                                q.first();
                                parking=(q.value(0).toInt());
        q.prepare("SELECT COUNT(ID_EQUIP) FROM EQUIPEMENTS ");
                q.exec();
                q.first();
                total=(q.value(0).toInt());
         salle_1=((double)salle_1/(double)total)*100;
         salle_2 =((double)salle_2/(double)total)*100;
         salle_3=((double)salle_3/(double)total)*100;
         parking =((double)parking/(double)total)*100;
         Salle_2 = QString::number(salle_2);
         Salle_1 = QString::number(salle_1);
         Salle_3 = QString::number(salle_3);
         Parking = QString::number(parking);

         QPieSeries *series;
                  series= new  QPieSeries();
                  series->append("salle 2 :"+Salle_2+"%",salle_2);
                  series->append("salle 1 :"+Salle_1+"%",salle_1);
                  series->append("salle 3 :"+Salle_3+"%",salle_3);
                  series->append("Parking :"+Parking+"%",parking);
                  QPieSlice *slice0 = series->slices().at(0);
         slice0->setLabelVisible();
         QPieSlice *slice1 = series->slices().at(1);
                      slice1->setExploded();
                      slice1->setLabelVisible();
                      slice1->setPen(QPen(Qt::yellow, 2));
                      slice1->setBrush(Qt::black);
                      QPieSlice *slice3 = series->slices().at(3);
             slice3->setLabelVisible();
             QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
                       QChart *chart = new QChart();
                       chart->addSeries(series);
                       chart->setTitle("Statistiques sur les equipements dans les locales");
                       chart->legend()->show();
                       QChartView *chartView = new QChartView(chart);
                       chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_2->addWidget(chartView);
    chartView->show();
    }
