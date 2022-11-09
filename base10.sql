/*==============================================================*/
/* DBMS name:      ORACLE Version 11g                           */
/* Created on:     25/10/2022 00:17:20                          */
/*==============================================================*/


/*==============================================================*/
/* Table: CLIENTS                                               */
/*==============================================================*/
create table CLIENTS 
(
   ID_CL                INTEGER              not null,
   NOM_CL               CHAR(10),
   PRENOM_CL            CHAR(10),
   PROFESSION_CL        CHAR(10),
   PAYEMENT_CL          CHAR(10)
);

alter table CLIENTS
   add constraint PK_CLIENTS primary key (ID_CL);

/*==============================================================*/
/* Table: EFFECTUER                                             */
/*==============================================================*/
create table EFFECTUER 
(
   ID_RESERVATION       INTEGER              not null,
   ID_CL                INTEGER              not null,
   DATE_DR              DATE,
   DATE_FR              DATE
);

alter table EFFECTUER
   add constraint PK_EFFECTUER primary key (ID_RESERVATION, ID_CL);

/*==============================================================*/
/* Table: EMPLOYES                                              */
/*==============================================================*/
create table EMPLOYES 
(
   ID_EMP               INTEGER              not null,
   NOM_EMP              CHAR(10),
   PRENOM_EMP           CHAR(20),
   POSTE_EMP            CHAR(30),
   SALAIRE_EMP          INTEGER
);

alter table EMPLOYES
   add constraint PK_EMPLOYES primary key (ID_EMP);

/*==============================================================*/
/* Table: EQUIPEMENTS                                           */
/*==============================================================*/
create table EQUIPEMENTS 
(
   ID_EQUIP             INTEGER              not null,
   TYPE_MAT             CHAR(20),
   NOM_MAT              CHAR(20),
   LOCALISTION_EQUIP    CHAR(20)
);

alter table EQUIPEMENTS
   add constraint PK_EQUIPEMENTS primary key (ID_EQUIP);

/*==============================================================*/
/* Table: FOURNIR                                               */
/*==============================================================*/
create table FOURNIR 
(
   ID_FOUR              INTEGER              not null,
   ID_EQUIP             INTEGER              not null,
   QTE_FOUR             INTEGER
);

alter table FOURNIR
   add constraint PK_FOURNIR primary key (ID_FOUR, ID_EQUIP);

/*==============================================================*/
/* Table: FOURNISSEURS                                          */
/*==============================================================*/
create table FOURNISSEURS 
(
   ID_FOUR              INTEGER              not null,
   ID_EMP               INTEGER              not null,
   NOM_FOUR             CHAR(10),
   TYPE_FOUR            CHAR(20)
);

alter table FOURNISSEURS
   add constraint PK_FOURNISSEURS primary key (ID_FOUR);

/*==============================================================*/
/* Table: PROCURER                                              */
/*==============================================================*/
create table PROCURER 
(
   ID_SPON              INTEGER              not null,
   ID_EQUIP             INTEGER              not null,
   QTE_SPON             INTEGER
);

alter table PROCURER
   add constraint PK_PROCURER primary key (ID_SPON, ID_EQUIP);

/*==============================================================*/
/* Table: RESERVATIONS                                          */
/*==============================================================*/
create table RESERVATIONS 
(
   ID_RESERVATION       INTEGER              not null,
   ESPACE_LOUE          CHAR(10)
);

alter table RESERVATIONS
   add constraint PK_RESERVATIONS primary key (ID_RESERVATION);

/*==============================================================*/
/* Table: SPONSORS                                              */
/*==============================================================*/
create table SPONSORS 
(
   ID_SPON              INTEGER              not null,
   NOM_SPON             CHAR(10),
   TYPE_SPON            CHAR(10),
   TYPE_EV              CHAR(10),
   MONTANT_PAYES        INTEGER,
   MONTANT_GAGNE        INTEGER
);

alter table SPONSORS
   add constraint PK_SPONSORS primary key (ID_SPON);

alter table EFFECTUER
   add constraint FK_EFFECTUE_EFFECTUER_RESERVAT foreign key (ID_RESERVATION)
      references RESERVATIONS (ID_RESERVATION);

alter table EFFECTUER
   add constraint FK_EFFECTUE_EFFECTUER_CLIENTS foreign key (ID_CL)
      references CLIENTS (ID_CL);

alter table FOURNIR
   add constraint FK_FOURNIR_FOURNIR_FOURNISS foreign key (ID_FOUR)
      references FOURNISSEURS (ID_FOUR);

alter table FOURNIR
   add constraint FK_FOURNIR_FOURNIR2_EQUIPEME foreign key (ID_EQUIP)
      references EQUIPEMENTS (ID_EQUIP);

alter table FOURNISSEURS
   add constraint FK_FOURNISS_CONTACTER_EMPLOYES foreign key (ID_EMP)
      references EMPLOYES (ID_EMP);

alter table PROCURER
   add constraint FK_PROCURER_PROCURER_SPONSORS foreign key (ID_SPON)
      references SPONSORS (ID_SPON);

alter table PROCURER
   add constraint FK_PROCURER_PROCURER2_EQUIPEME foreign key (ID_EQUIP)
      references EQUIPEMENTS (ID_EQUIP);

