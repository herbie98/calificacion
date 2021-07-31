<?php

class Calificaciones{
  protected $Coneccion;
  protected $BasedeDatos;
  protected $sql;
  protected $consulta;

  public function _cosntruct(){
     $this->Coneccion = ""; // Coneccion
     $this->BasedeDatos = "";   // Base de datos
     $this->sql = ""; // query
     $this->consulta = ""; // Resultado de la cosulta
  }

  public function conectar(){
     $this->Coneccion = mysqli_connect("localhost", "Timothy", "123456","Calificaciones");

     if (!$this->Coneccion)
       die ("<h3>*** ERROR al conectar... :(-{ </h3>");

  }
    
  public function cerrarconexion(){
        mysqli_close($this->Coneccion);
  }
    
  public function InsertarDatoAlumno($Alumno){ // Tabla - Arreglo de Datos a isertar 
        $SQL = "insert into Calificacion ( nombre,matricula,matematica,espanol,ingles )
        values ( '".$Alumno->getNombre()."',".$Alumno->getMatricula().",".$Alumno->getMatematicas().",".$Alumno->getEspañol().",
                                        ".$Alumno->getIngles().");";
        
        $this->sql = mysqli_query($this->Coneccion,$SQL);
        if(!$this->sql){
           echo "<h1> Errorn en la Insercion <h1>";
        }
    }
    
    // Actualizar Registro 
  public function ActualizarRegistroAlumno($Alm){ // Tabla - Arreglo de Datos a isertar  
        
        $SQL = "UPDATE Calificacion SET nombre = '".$Alm->getNombre()."', 
                                           matricula = ".$Alm->getMatricula().",
                                           matematica = ".$Alm->getMatematicas().", 
                                           espanol=" .$Alm->getEspañol().",
                                           ingles = ".$Alm->getIngles()." 
                                           WHERE matricula = ".$Alm->getMatricula().";";
        
        
        $resul = mysqli_query($this->Coneccion,$SQL);
        if(!$resul){
           echo "<h1> Errorn en la Actualizacion <h1>";
        }
    }
    
         // Eliminar Dato en la Base de datos
  public function EliminarDatos($Dabuscar){  // Tabla -  con dato a buscar 
        $this->sql = mysqli_query($this->Coneccion," DELETE FROM Calificacion  WHERE matricula = ".$Dabuscar.";");
        if(!$this->sql)
            die("<h3>ERROR: al Eliminar Dato</h3>" ); 
    } 
    
    // Consulta General
  public function PaguinacionCalificaciones(){ 
        $pagina = "";
        $registros = 10;
        $colores_filas=array('#cccccc', 'lightblue');
        $ind_colores=0;
        $cont_lineas=1;     

        if(isset($_GET['pagina']))
                $pagina = $_GET['pagina'];


        if (!$pagina) 
        { 
            $inicio = 0; 
            $pagina = 1; 
        }  
        else
        { 
          $inicio = ($pagina - 1) * $registros; 
        } 
        $resultados = mysqli_query($this->Coneccion,"SELECT * from Calificacion;");   
        $total_registros = mysqli_num_rows($resultados); 
        $resultados = mysqli_query($this->Coneccion,"SELECT * FROM Calificacion ORDER BY nombre ASC   LIMIT $inicio, $registros");	
        $total_paginas = ceil($total_registros / $registros); 		  			

	   if($total_registros) 
       {

           $colores_filas=array('#cccccc', 'lightblue');
           $ind_colores=0;
           $cont_lineas=1;     
           $Actu = "Actualizar";
           while ($row = mysqli_fetch_array($resultados))
           {
               $ind_colores++;
               $ind_colores %= 2;
               $dato=$row{'nombre'};
               echo "<tr bgcolor=".$colores_filas[$ind_colores].">";
                         echo "<td>".$cont_lineas."</td>";
                         echo "<td>".$row['nombre']."</td>"; 
                         echo "<td>".$row['matricula']."</td>"; 
                         echo "<td>".$row['matematica']."</td>"; 
                         echo "<td>".$row['espanol']."</td>"; 
                         echo "<td>".$row['ingles']."</td>"; 
                         echo "<td>".(($row['matematica']+$row['espanol']+$row['ingles'])/3)."</td>";
                         echo "<td><a href='index.php?nombre=".$row['nombre']."&matricula=".
                                                               $row['matricula']."&matematica=".
                                                               $row['matematica']."&espanol=".
                                                               $row['espanol']."&ingles=".
                                                               $row['ingles']."&iden=Update&'> Actualizar</a></td>"; 
                         echo "<td><a href='index.php?nombre=".$row['nombre']."&matricula=".
                                                               $row['matricula']."&matematica=".
                                                               $row['matematica']."&espanol=".
                                                               $row['espanol']."&ingles=".
                                                               $row['ingles']."&iden=Update&'> Eliminar</a></td>"; 
                 
               $cont_lineas++;
           }
           if($cont_lineas==1) return false;
	   } 
       else 
       {
		  echo "<font color='darkgray'>(sin resultados)</font>";
	   }

       mysqli_free_result($resultados);		
       echo "<div class='pagination'> 
                  <ul>";		
	   
	   if($total_registros) 
       {	
		  if(($pagina - 1) > 0)
          {
              echo "<li><a  href='index.php?pagina=".($pagina-1)."'> Anterior</a> </li>";
          }
		
           for ($i=1; $i<=$total_paginas; $i++){ 
			 if ($pagina == $i) 
             echo "<li> <a><b>".$pagina."</b></a></li>"; 
               else
                   echo "<li><a href='index.php?pagina=$i'>$i</a> </li>"; 
		  }	   
		  if(($pagina + 1)<=$total_paginas) 
          {
			 echo "<li><a href='index.php?pagina=".($pagina+1)."'>Siguiente </a></li>";
		  }
		
		 
		
           }
           echo "   </ul>
                </div>";	
        echo "<center>Total de registros: $total_registros ";
	    echo "Inicio: $inicio ";
	    echo "Registros: $registros ";
	    echo "No de Pagina: $pagina </center>";
	
   
    }
}

  class Alumnos{
           
           private $Nombre;
           private $Matricula;
           private $Matematicas;
           private $Español;
           private $Ingles;
           
           function __construct() {
               $this->Nombre = "";
               $this->Matricula = "";
               $this->Matematicas = "";
               $this->Español = "";
               $this->Ingles = "";
           }
           function getNombre() {
               return $this->Nombre;
           }

           function getMatricula() {
               return $this->Matricula;
           }

           function getMatematicas() {
               return $this->Matematicas;
           }

           function getEspañol() {
               return $this->Español;
           }

           function getIngles() {
               return $this->Ingles;
           }

           function setNombre($Nombre) {
               $this->Nombre = $Nombre;
           }

           function setMatricula($Matricula) {
               $this->Matricula = $Matricula;
           }

           function setMatematicas($Matematicas) {
               $this->Matematicas = $Matematicas;
           }

           function setEspañol($Español) {
               $this->Español = $Español;
           }

           function setIngles($Ingles) {
               $this->Ingles = $Ingles;
           }

       
       }