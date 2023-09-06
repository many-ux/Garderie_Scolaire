#ifndef ELEVE_H
#define ELEVE_H
#include "qdatetime.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Eleve
{
    QString nom,prenom,mail,adresse,sexe;
    int cin,numparent;
    QDate datenaissance,dateIns;
public:
    Eleve(){};
    Eleve(int,QString,QString,QString,QString,QDate,int,QString,QDate);
    int getcin(){return cin;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QDate getdate(){return datenaissance;}
    int getnumtel(){return numparent;}
    QString getadresse(){return adresse;}
    QString getmail(){return mail;}
    QString getsexe(){return sexe;}
    QDate getdateIns(){return dateIns;}


    void setcin(int cin){this->cin=cin;}
    void setnom(QString n){this->nom=n;}
    void setprenom(QString p){this->prenom=p;}
    void setdate(QDate d){this->datenaissance=d;}
    void setnumtel(int num){this->numparent=num;}
    void setadresse(QString ad){this->adresse=ad;}
    void setmail(QString ma){this->mail=ma;}
    void setsexe(int se){this->sexe=se;}


    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer(int cin);
    QSqlQueryModel * trier();
    QSqlQueryModel * triernom();
    QSqlQueryModel * triercin();
    QSqlQueryModel *RechercheNom(QString);
    QSqlQueryModel *RecherchePrenom(QString);
    QSqlQueryModel *Recherche(int);




};

#endif // ELEVE_H
