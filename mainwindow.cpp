#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow) {
	ui->setupUi(this);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_pushBtn_generate_clicked() {

	QTextEdit *resualt = ui->textEdit_resualt;

	const QString link = ui->lineEdit_link->text();
	const int num = ui->spinBox_num->value();
	const int index = link.indexOf("***");

	if (index == -1) {

		resualt->setText("لطفا بجای عددی که قرار است تغییر کند *** بزارید");

	}

	else {

		resualt->setText("");

		for (int i = 1; i <= num ; ++i) {

			QString temp = link;

			if (i >= 10 && i < 100) {
				temp.remove(index - 1, 1);
			}
			else if (i >= 100 && i < 1000) {
				temp.remove(index - 2, 2);
			}
			else if (i >= 1000) {
				temp.remove(index - 3, 3);
			}

			temp.replace("***", QString::number(i));
			resualt->setText(resualt->toPlainText() + temp + "\n");

		}

	}

}
