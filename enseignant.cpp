#include "ui_mainwindow.h"
#include "enseignant.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>

Enseignant::Enseignant(int cin,QString nom,QString prenom,QString sexe,QString mail,QDate datenaissance,float salaire,int numtel,QString adresse, QDate datens)
{

    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->mail=mail;
    this->datenaissance=datenaissance;
    this->salaire=salaire;
    this->numtel=numtel;
    this->adresse=adresse;
    this->datens=datens;
}



bool Enseignant::ajouter()
{
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString num_string = QString::number(numtel);
    QString salary_string = QString::number(salaire);

    query.prepare("insert into enseignant(cin, nom, prenom, sexe, mail,datenaissance,salaire,numtel,adresse,datens)"
                  "VALUES(:cin,:nom,:prenom,:sexe, :mail,:datenaissance,:salaire,:numtel,:adresse,:datens)");
    query.bindValue(":cin",cin_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);
    query.bindValue(":mail",mail);
    query.bindValue(":datenaissance",datenaissance);
    query.bindValue(":salaire",salary_string);
    query.bindValue(":numtel",num_string);
    query.bindValue(":adresse",adresse);
    query.bindValue(":datens",datens);
    return query.exec();
}


QSqlQueryModel * Enseignant::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * from enseignant");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("datens"));
    return model;


}

bool Enseignant::modifier()
{
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString num_string = QString::number(numtel);
    QString salary_string = QString::number(salaire);
    query.prepare("UPDATE enseignant SET cin = :cin, nom = :nom, prenom = :prenom, sexe = :sexe, mail = :mail, datenaissance = :datenaissance, salaire = :salaire, numtel = :numtel, adresse = :adresse, datens = :datens WHERE cin = :cin");
    query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":mail", mail);
    query.bindValue(":datenaissance", datenaissance);
    query.bindValue(":salaire", salary_string);
    query.bindValue(":numtel", num_string);
    query.bindValue(":adresse", adresse);
    query.bindValue(":datens", datens);
    return query.exec();
}

bool Enseignant::supprimer(int cin)
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    query.prepare("delete from enseignant where cin= :cin");
    query.bindValue(":cin", cin_string);
    return query.exec();
}


QSqlQueryModel * Enseignant::trierprenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT* from enseignant order by prenom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("datens"));
    return model;
}

QSqlQueryModel * Enseignant::triernom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT* from enseignant order by nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("datens"));
    return model;
}


QSqlQueryModel * Enseignant::triercin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT* from enseignant order by cin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("datens"));
    return model;
}

QSqlQueryModel *Enseignant::RechercheNom(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from enseignant where nom like'%"+a+"%' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("datens"));
    return model;
}

QSqlQueryModel *Enseignant::RecherchePrenom(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from enseignant where prenom like'%"+a+"%' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("datens"));
    return model;
}

QSqlQueryModel* Enseignant::recherche(int cin){
    QSqlQuery query;
    QString cin_string=QString::number(cin);

    query.prepare("SELECT * from enseignant where cin=:cin");
    query.bindValue(":cin", cin_string);

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery(query);

    return model;

}

void Enseignant::creerPDF(){
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM ENSEIGNANT ");
    q.exec();
    QString pdf="<br> <h1  style='color:blue'>LISTE DES ENSEIGNANTS  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>NOM </th> <th>PRENOM  </th> <th>SEXE  </th> <th>  MAIL  </th> <th>DATE DE NAISSANCE  </th><th>SALAIRE   </th> <th><th>NUMERO DE TELEPHONE   </th> <th>ADRESSE   </th> <th>DATE D'EMPLOIEMENT </tr></th>  " ;
    while ( q.next())
    {
        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;
    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

QtCharts::QChartView * Enseignant::stat()
{
    int row_count = 0;
    int row_count1 = 0;
    int row_count2 = 0;
    QSqlQuery query,query2,query3;
    query.prepare("SELECT * FROM enseignant where salaire < 1000 ");
    query.exec();
    query2.prepare("SELECT * FROM enseignant where (salaire >= 1000) AND (salaire < 5000) ");
    query2.exec();
    query3.prepare("SELECT * FROM enseignant where salaire >= 5000");
    query3.exec();

    while(query3.next())
        row_count2++;

    while(query2.next())
        row_count1++;

    while(query.next())
        row_count++;

    qDebug()<<row_count<<row_count1<<row_count2;

    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();
    series->append("enseignants au salaire > 5000 DT", row_count2);
    series->append("enseignants au salaire entre 5000 et 1000 DT", row_count1);
    series->append("enseignants au salaire <1000 DT", row_count);
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique Des Salaires");
    chart->setAnimationOptions(QtCharts::QChart::AllAnimations);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setBackgroundVisible(true);
    chart->legend()->setBrush(QBrush(QColor(60, 60, 60, 60)));
    chart->legend()->setPen(QPen(QColor(108, 106, 0)));
    series->setLabelsVisible();

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}



