create database Calificaciones;
use Calificaciones;

create table Calificacion(
    matricula bigint not null,
    nombre varchar(100) not null,
    matematica decimal(7,2) default 0,
    espanol decimal(7,2) default 0,
    ingles decimal(7,2) default 0,
    primary key(matricula)    
);