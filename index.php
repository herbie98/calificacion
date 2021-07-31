<!doctype html>
<html>
    <head>
       <title>Registro de Alumnos</title>    
    </head>
    <body>            
   
    <header id="main-header">         
    
    </header > 
        
            <form action="Datos.php" method="post" name="Formularios">
               <table>
                   <tr>
                       <td>Nombre</td>
                       <td><input type="tex" name="nombre" placeholder="Nombre" value="<?php echo $Nombre; ?>"></td>
                   </tr>
                   <tr>
                       <td>Matricula</td>
                       <td><input type="number" name="matricula" placeholder="Matricula" value="<?php echo $Matricula; ?>"></td>
                   </tr>
                   <tr>
                       <td>Matematicas</td>
                       <td><input type="number"name="matematicas" placeholder="Matematicas" value="<?php echo $Matematicas; ?>"></td>
                   </tr>
                   <tr>
                       <td>Español</td>
                       <td><input type="number"name="espanol" placeholder="Español" value="<?php echo $Espanol; ?>"></td>
                   </tr>
                   <tr>
                       <td>Ingles</td>
                       <td><input type="number"name="ingles" placeholder="Ingles" value="<?php echo $Ingles; ?>"></td>
                       <input type="hidden" name="indetificadorCU" value="<?php echo $indetificadorCU;?>">
                   </tr>
                   <tr>
                       <td colspan="2"><input type="submit" value="enviar<?php echo $IndetificacionCreateUpedtae; ?>"></td>
                   </tr>
               </table>
               
            </form>
           <section>               
                     <table>
                            <tr>
                                <th> </th>
                                <th>Nombre</th>
                                <th>Matricula</th>
                                <th>Matematicas </th>
                                <th>Español </th>                                
                                <th>Ingles</th>
                                <th>Promedio</th>
                                <th>Editar</th>
                                <th>Eliminar</th>    
                            </tr>
                            <tr>
                                 <?php
                                 $ObjCon = new Calificacion();
                                 $ObjConn->Conectar(); // Conectamos
                                 $ObjConn->PaguinacionCalificaciones();
                                ?>
                            </tr>
                     </table>
                    
            </section>
    </body>
</html>
<?php 

// Incluyo Objetos Con>eccion
include("Objetos.inc");
// Varibles de Indentificacion
$IndetificacionCreateUpedtae = "Inserta Calificacion";
$indetificadorCU = "Insert";

$Nombre = "";
$Matricula = "";
$Matematicas = "";
$Espanol = "";
$Ingles = "";


if(isset( $_GET['iden'])){
    
    $Nombre =  $_GET['nombre'];
    $Matricula =  $_GET['matricula'];
    $Matematicas =  $_GET['matematica'];
    $Espanol =  $_GET['espanol'];
    $Ingles =  $_GET['ingles'];
     
    
    if($_GET['iden'] == "Insert"){ // Indentificador de la accion Insertar Empleado
        
        $indetificadorCU = "Insert";
        $IndetificacionCreateUpedtae = "Inserta Calificacion";
        
       
        
    }else if($_GET['iden'] == "Update"){ // Indentificador de la accion Actualizar  Empleado
        
        $indetificadorCU = "Update";
        $IndetificacionCreateUpedtae = "Actualizar  Calificacion";
        
      
        
      
        
    }else if($_GET['iden'] == "Delete"){ // Indentificador de la accion Eliminar  Empleado
        
        $ObjCon = new Calificaciones();
        $ObjCon->Conectar(); // Conectamos        
        $ObjCon->EliminarDatos($Matricula);
        $ObjCon->cerrarconexion();
        header('Location:index.php'); 
    }
    
    
    
}
?>