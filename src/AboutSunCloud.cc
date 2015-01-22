#include "include/AboutSunCloud.h"
#include "include/ui_AboutSunCloud.h"

AboutSunCloud::AboutSunCloud(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutSunCloud)
{
    ui->setupUi(this);
}

AboutSunCloud::~AboutSunCloud()
{
    delete ui;
}
