#include "eleve.h"
#include "ui_mainwindow.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>

Eleve::Eleve(int cin,QString nom,QString prenom,QString sexe,QString mail,QDate datenaissance,int numparent,QString adresse,QDate dateIns)
{

    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->mail=mail;
    this->datenaissance=datenaissance;
    this->numparent=numparent;
    this->adresse=adresse;
    this->dateIns=dateIns;
}
bool Eleve::ajouter()
{
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString num_string = QString::number(numparent);
    query.prepare("INSERT INTO eleve (cin, nom, prenom, sexe, mail, datenaissance, adresse, numparent, dateins) "
                  "VALUES (:cin, :nom, :prenom, :sexe, :mail, :datenaissance, :adresse, :numparent, :dateins)");
    query.bindValue(":cin",cin_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":sexe",sexe);
    query.bindValue(":datenaissance",datenaissance);
    query.bindValue(":numparent",num_string);
    query.bindValue(":adresse",adresse);
    query.bindValue(":dateins",dateIns);
    return query.exec();
}


QSqlQueryModel * Eleve::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * from eleve");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numparent"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("dateins"));
    return model;
}


bool Eleve::modifier()
{
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString num_string = QString::number(numparent);
    query.prepare("UPDATE eleve SET cin = :cin, nom = :nom, prenom = :prenom, sexe = :sexe, mail = :mail, datenaissance = :datenaissance, numparent = :numparent, adresse = :adresse , dateIns = :dateIns WHERE cin = :cin");

    query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":mail", mail);
    query.bindValue(":datenaissance", datenaissance);
    query.bindValue(":numparent", num_string);
    query.bindValue(":adresse", adresse);
    query.bindValue(":dateIns", dateIns);
    return query.exec();
}

bool Eleve::supprimer(int cin)
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    query.prepare("delete from eleve where cin= :cin");
    query.bindValue(":cin", cin_string);
    return query.exec();
}


QSqlQueryModel * Eleve::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT* from eleve");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numparent"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("dateins"));
    return model;
}

QSqlQueryModel * Eleve::triernom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT* from enseignant order by nom");
    model->setQuery("SELECT* from eleve");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numparent"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("dateins"));
    return model;
}


QSqlQueryModel * Eleve::triercin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT* from eleve order by cin");
    model->setQuery("SELECT* from eleve");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numparent"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("dateins"));
    return model;
}

QSqlQueryModel *Eleve::RechercheNom(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from eleve where nom like'%"+a+"%' ");
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

QSqlQueryModel *Eleve::RecherchePrenom(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from eleve where prenom like'%"+a+"%' ");
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

QSqlQueryModel* Eleve::Recherche(int cin){
    QSqlQuery query;
    QString cin_string=QString::number(cin);

    query.prepare("SELECT * from eleve where cin=:cin");
    query.bindValue(":cin", cin_string);

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery(query);

    return model;

}
