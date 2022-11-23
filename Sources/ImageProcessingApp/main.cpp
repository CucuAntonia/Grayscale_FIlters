#include <QApplication>
#include "mainwindow.h"

	int main(int argc, char* argv[])
	{
		QApplication a(argc, argv);

		//Set the application stylesheet
		//__FILE__
		QString pathToQss = "D:\\VS_Projects\\Practica_bun\\PracticaSpring2022\\Resources\\Combinear.qss";
		QFile styleSheetFile(pathToQss);
		styleSheetFile.open(QFile::ReadOnly);
		QString styleSheet = QLatin1String(styleSheetFile.readAll());
		a.setStyleSheet(styleSheet);
		MainWindow w;
		w.resize(1100, 700);
		w.show();
		return a.exec();
	}


