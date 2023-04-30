Algoritmo ProyectoFinalDeR
	Escribir 'REFERENCIAS: 1-ADELANTE, 2-ATRAS, 3-DERECHA, 4-IZQUIERDA, 0-INICIO'
	Escribir '------------------------------------------------------------------'
	InicializarComponentes()
	// Se asume un límite de 10 tarjetas
	Dimension secuenciaProgramacion[10]
	InicializarsecuenciaProgramacion(secuenciaProgramacion)
	Mientras Verdadero Hacer
		Escribir 'Ingrese 1 si el ingreso de datos es por Bluetooth'
		Escribir 'Ingrese 2 si el ingreso es mediante tarjetas RFID'
		Leer respuestaUsuario
		Si respuestaUsuario==1 Entonces
			CargarSecuenciaProgramacionDesdeBluetooth(secuenciaProgramacion)
			EjecutarSecuenciaProgramacion(secuenciaProgramacion)
			InicializarsecuenciaProgramacion(secuenciaProgramacion)
		FinSi
		Si respuestaUsuario==2 Entonces
			CargarSecuenciaProgramacion(secuenciaProgramacion)
			EjecutarSecuenciaProgramacion(secuenciaProgramacion)
			InicializarsecuenciaProgramacion(secuenciaProgramacion)
		FinSi
	FinMientras
FinAlgoritmo

Funcion InicializarsecuenciaProgramacion(secuenciaProgramacion)
	Para i<-1 Hasta 10 Hacer
		secuenciaProgramacion[i] <- 0;
	FinPara
FinFuncion

Funcion EjecutarSecuenciaProgramacion(secuenciaProgramacion)
	SonidoInicioEjecucionSecuencia()
	indiceTarjeta <- 1
	Mientras indiceTarjeta<=10 Y secuenciaProgramacion[indiceTarjeta]<>0 Hacer
		Segun secuenciaProgramacion[indiceTarjeta]  Hacer
			1:
				// Código para ir hacia adelante
				MoverAdelante()
				MostrarFlechaArriba()
			2: // Código para ir hacia atrás
				MoverAtras()
				MostrarFlechaAbajo()
			3: // Código para ir hacia la derecha
				MoverDerecha()
				MostrarFlechaDerecha()
			4: // Código para ir hacia la izquierda
				MoverIzquierda()
				MostrarFlechaIzquierda()
		FinSegun
		indiceTarjeta <- indiceTarjeta+1
	FinMientras
	Escribir ' --- Fin de secuencia ---'
	SonidoFinEjecucionSecuencia()
	DetenerMotores()
FinFuncion

Funcion InicializarComponentes
	Escribir 'Inicializando módulo RFID'
	Escribir 'Inicializando buzzer'
	Escribir 'Inicializando motores'
	Escribir 'Inicializando módulo de bluetooth'
	Escribir 'Inicializando display'
FinFuncion

Funcion CargarSecuenciaProgramacion(secuenciaProgramacion)
	Escribir 'Introducir las tarjetas: '
	indiceTarjeta <- 1
	salir <- falso
	Mientras !salir Y indiceTarjeta<=10 Hacer
		Leer tarjeta
		SonidoNuevaTarjetaCargada()
		secuenciaProgramacion[indiceTarjeta] <- tarjeta
		indiceTarjeta <- indiceTarjeta+1
		Si tarjeta == 0
			salir <- Verdadero
		FinSi
	FinMientras
FinFuncion

Funcion CargarSecuenciaProgramacionDesdeBluetooth(secuenciaProgramacion)
	Escribir 'Leyendo desde Bluetooth: '
	indiceTarjeta <- 1
	salir <- falso
	Mientras !salir Y indiceTarjeta<=10 Hacer
		Leer tarjeta
		SonidoNuevaTarjetaCargada()
		secuenciaProgramacion[indiceTarjeta] <- tarjeta
		indiceTarjeta <- indiceTarjeta+1
		Si tarjeta == 0
			salir <- Verdadero
		FinSi
	FinMientras
FinFuncion

// ------------------------------------ Funciones Buzzer -----------------------------------
Funcion SonidoNuevaTarjetaCargada
	Escribir 'Buzzer emite sonido Nueva Tarjeta'
FinFuncion

Funcion SonidoInicioEjecucionSecuencia
	Escribir 'Buzzer emite sonido Inicio Ejecución Secuencia'
FinFuncion

Funcion SonidoFinEjecucionSecuencia
	Escribir 'Buzzer emite sonido Fin Ejecución Secuencia'
FinFuncion

// ------------------------------------ Fin Funciones Buzzer -----------------------------------
// ------------------------------------ Funciones Motores -----------------------------------
Funcion MoverAdelanteM1
	Escribir 'Mover el motor M1 adelante'
FinFuncion

Funcion MoverAdelanteM2
	Escribir 'Mover el motor M2 adelante'
FinFuncion

Funcion MoverAtrasM1
	Escribir 'Mover el motor M1 atrás'
FinFuncion

Funcion MoverAtrasM2
	Escribir 'Mover el motor M2 atras'
FinFuncion

Funcion MoverAdelante
	Escribir ' --- Moviendo robot hacia adelante ---'
	MoverAdelanteM1()
	MoverAdelanteM2()
FinFuncion

Funcion MoverAtras
	Escribir ' --- Moviendo robot hacia atrás ---'
	MoverAtrasM1()
	MoverAtrasM2()
FinFuncion

Funcion DetenerMotores
	Escribir 'Detener motor M1'
	Escribir 'Detener motor M2'
FinFuncion

Funcion MoverDerecha
	Escribir ' --- Moviendo robot hacia la derecha ---'
	MoverAtrasM2()
	MoverAdelanteM1()
FinFuncion

Funcion MoverIzquierda
	Escribir ' --- Moviendo robot hacia la izquierda ---'
	MoverAtrasM1()
	MoverAdelanteM2()
FinFuncion

// ------------------------------------ Funciones Display -----------------------------------
Funcion MostrarFlechaArriba
	Escribir 'Dibujar Flecha arriba'
FinFuncion

Funcion MostrarFlechaAbajo
	Escribir 'Dibujar Flecha abajo'
FinFuncion

Funcion MostrarFlechaDerecha
	Escribir 'Dibujar Flecha derecha'
FinFuncion

Funcion MostrarFlechaIzquierda
	Escribir 'Dibujar Flecha izquierda'
FinFuncion
