Esc�ner de libros autom�tico.
============================
######Proyecto de Mario Navarro y Pablo Ot�n para la asignatura Automatizaci�n Industrial de 3� del Grado en Ingenier�a Electr�nica industrial y autom�tica de la UPCT.
![Imagen1](http://i.gyazo.com/fb20c3760d65ccf924531efab7c1a3b4.png)
![Imagen2](http://i.gyazo.com/1a5dec6576b23358d52b24a8013a377f.png)

#1.-C�digo Arduino
...
##1.1-Librer�as Usadas
######Para hacer funcionar el c�digo hay que incluir las dos librer�as siguientes:
###1.1.1.-Librer�a FSM
######Librer�a 'FSM' para poder imlementar con Arduino la secuencia de funcionamiento en formato de m�quina de estados.
######Creada por Igor Real.
######Descargar en: https://github.com/IgorReal/SECUduino/tree/master/FSM%20Library
###1.1.2.-Librer�a Unipolar
######Librer�a 'Unipolar' propia, para el control del motor paso a paso unipolar 28BYJ48.
######Descargar en: https://github.com/PabloOton/Libreria-24BYJ48

#2.-Hardware
##2.1.-Electr�nica
######Finales de carrera superior e inferior: El inferior lo hemos sustituido por un presostato y el superior realmente no es necesario, al tratarse de un motor paso a paso; Pero en este primer prototipo nos decantamos por poner el final de carrera superior porque a la hora de hacer los numerosos ajustes es m�s c�modo cambiar la posici�n del final de carrera que reajustar los pasos del motor.
##2.2.-Neum�tica
...

#3.-Modificaciones pendientes, mejoras
######No depender del sistema neum�tico.
######Cambiar el motor de la cremallera por uno m�s r�pido. 
######Display con encoder para configuraci�n e introducir n� de p�ginas a escanear.



