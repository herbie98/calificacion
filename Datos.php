<?php

include('Objetos.inc');

// Codigo identificador de datos de un formulario 
if(isset($_POST['Identificador']))
    $Indentificador = $_POST['Identificador'];
if(isset($_GET['Identificador']))
    $Indentificador = $_GET['Identificador'];

$ObjConn = new  Calificaciones();    
$ObjAlum = new Alumnos();
$ObjAlum->setNombre($_POST['nombre']);
$ObjAlum->setMatricula($_POST['matricula']);
$ObjAlum->setMatematicas($_POST['matematicas']);
$ObjAlum->setEspañol($_POST['espanol']);
$ObjAlum->setIngles($_POST['ingles']);
    
    
if($_POST['indetificadorCU'] == "Insert"){
 
  
    $ObjConn->Conectar(); // Conectamos
    $ObjConn->InsertarDatoAlumno($ObjAlum);
    $ObjConn->cerrarconexion();
    header('Location:index.php');  
        
        
}else if($_POST['indetificadorCU'] == "Update"){
        //  Empleados
    $ObjCon = new  Calificaciones();  
    $ObjAlum->setMatricula($_POST['matricula']);     
    $ObjCon->Conectar(); // Conectamos
    $ObjCon->ActualizarRegistroAlumno($ObjAlum);
    $ObjCon->cerrarconexion();
    header('Location:index.php');  
        
}