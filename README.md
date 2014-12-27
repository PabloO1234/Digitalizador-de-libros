Escáner de libros automático.
============================
######Proyecto de Mario Navarro y Pablo Otón para la asignatura Automatización Industrial de 3º del Grado en Ingeniería Electrónica industrial y automática de la UPCT.
![Imagen1](http://i.gyazo.com/fb20c3760d65ccf924531efab7c1a3b4.png)
![Imagen2](http://i.gyazo.com/1a5dec6576b23358d52b24a8013a377f.png)

#1.-Código Arduino
...
##1.1-Librerías Usadas
######Para hacer funcionar el código hay que incluir las dos librerías siguientes:
###1.1.1.-Librería FSM
######Librería 'FSM' para poder imlementar con Arduino la secuencia de funcionamiento en formato de máquina de estados.
######Creada por Igor Real.
######Descargar en: https://github.com/IgorReal/SECUduino/tree/master/FSM%20Library
###1.1.2.-Librería Unipolar
######Librería 'Unipolar' propia, para el control del motor paso a paso unipolar 28BYJ48.
######Descargar en: https://github.com/PabloOton/Libreria-24BYJ48

#2.-Hardware
##2.1.-Electrónica
######Finales de carrera superior e inferior: El inferior lo hemos sustituido por un presostato y el superior realmente no es necesario, al tratarse de un motor paso a paso; Pero en este primer prototipo nos decantamos por poner el final de carrera superior porque a la hora de hacer los numerosos ajustes es más cómodo cambiar la posición del final de carrera que reajustar los pasos del motor.
##2.2.-Neumática
...

#3.-Modificaciones pendientes, mejoras
######No depender del sistema neumático.
######Cambiar el motor de la cremallera por uno más rápido. 
######Display con encoder para configuración e introducir nº de páginas a escanear.



