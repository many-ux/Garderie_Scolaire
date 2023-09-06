#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#include "qdatetime.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QChartView>
#include<QPieSeries>


class Enseignant
{
    QString nom,prenom,mail,adresse,sexe;
    int cin,numtel;
    float salaire;
    QDate datenaissance,datens;
public:
    Enseignant(){};
    Enseignant(int, QString, QString ,QString);
    Enseignant(int,QString,QString,QString,QString,QDate,float,int,QString, QDate);
    int getcin(){return cin;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QDate getdate(){return datenaissance;}
    int getnumtel(){return numtel;}
    QString getadresse(){return adresse;}
    QString getmail(){return mail;}
    QDate getdatemploy(){return datens;}
    float getsalaire(){return salaire;}
    QString getsexe(){return sexe;}


    void setcin(int cin){this->cin=cin;}
    void setnom(QString n){this->nom=n;}
    void setprenom(QString p){this->prenom=p;}
    void setdate(QDate d){this->datenaissance=d;}
    void setnumtel(int num){this->numtel=num;}
    void setadresse(QString ad){this->adresse=ad;}
    void setmail(QString ma){this->mail=ma;}
    void setdatemploy(QDate date){this->datens=date;}
    void setsalaire(int sal){this->salaire=sal;}
    void setsexe(int se){this->sexe=se;}

    bool ajouter();
    QSqlQueryModel *afficher();
    QSqlQueryModel * afficher1();
    QSqlQueryModel * afficher2();
    QSqlQueryModel * afficher3();
    bool modifier();
    bool supprimer(int cin);
    QSqlQueryModel * RechercheNom(QString);
    QSqlQueryModel *RecherchePrenom(QString);
    QSqlQueryModel * recherche(int);
    QSqlQueryModel * trierprenom();
    QSqlQueryModel * triernom();
    QSqlQueryModel * triercin();
    void creerPDF();
    QtCharts::QChartView *stat();


};

#endif // ENSEIGNANT_H
