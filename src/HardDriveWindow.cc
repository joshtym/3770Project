#include <QtGui>
#include "HardDriveWindow.h"

HardDriveWindow::HardDriveWindow()
{
   initValues();
   loadSpecs();
   loadAssets();
   initVectorValues();
}

HardDriveWindow::~HardDriveWindow()
{
}

void HardDriveWindow::initVectorValues()
{
   // Set our price labels and prices
   itemPriceLabels[0]->setText("$209.99");
   itemPrices.push_back(209.99);
   itemPriceLabels[1]->setText("$129.99");
   itemPrices.push_back(129.99);
   itemPriceLabels[2]->setText("$99.99");
   itemPrices.push_back(99.99);
   itemPriceLabels[3]->setText("$99.99");
   itemPrices.push_back(99.99);
   itemPriceLabels[4]->setText("$65.99");
   itemPrices.push_back(65.99);
   itemPriceLabels[5]->setText("64.99");
   itemPrices.push_back(64.99);
   
   // Set our check box values
   boxOptions[0]->setText("Seagate 4TB Internal HDD");
   boxOptions[1]->setText("WD Red 2TB Internal HDD");
   boxOptions[3]->setText("WD Blue 1TB Internal HDD");
   boxOptions[2]->setText("Seagate Hybrid 1TB HDD");
   boxOptions[4]->setText("WD Blue 500GB Internal HDD");
   boxOptions[5]->setText("WD Blue 250GB Internal HDD");
   
   // Set our minimum width
   for (int i = 0; i < 6; ++i)
      boxOptions[i]->setMinimumWidth(250);
}

void HardDriveWindow::loadSpecs()
{
   // Hard Code all of our details (Ideally, you'd use a web scraper or something)
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:25px\">Seagate ST4000VN000</p"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: Seagate</p"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: NAS HDD</p"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Performance</b></p"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Interface: SATA 6.0Gb/s</p"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 4TB</p"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Cache: 64MB</p"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: 3.5\"</p"));
   
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:25px\">Western Digital WD20EFRX</p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: WD</p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Red</p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Performance</b></p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Interface: SATA 6.0Gb/s</p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 2TB</p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">RPM: 5400 RPM</p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Cache: 64MB</p"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: 3.5\"</p"));
   
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:25px\">Seagate ST1000DX001</p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: Seagate</p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Desktop SSHD</p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Performance</b></p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Interface: SATA 6.0Gb/s</p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 1TB</p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Flash Memory Capacity: 8GB</p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Cache: 64MB</p"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: 3.5\"</p"));
   
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:25px\">Western Digital WD10JPVX</p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: WD</p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Blue</p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Performance</b></p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Interface: SATA 6.0Gb/s</p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 1TB</p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Cache: 8MB</p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">RPM: 5400 RPM</p"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: 2.5\"</p"));
   
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:25px\">Western Digital WD5000LPCX</p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: WD</p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Blue</p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Performance</b></p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Interface: SATA 6.0Gb/s</p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 500GB</p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Cache: 16MB</p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">RPM: 5400 RPM</p"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: 2.5\"</p"));
   
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:25px\">Western Digital WD2500AAKX</p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: WD</p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Blue</p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Performance</b></p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Interface: SATA 6.0Gb/s</p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 250GB</p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Cache: 16MB</p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">RPM: 7200 RPM</p"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: 3.5\"</p"));
}

void HardDriveWindow::loadAssets()
{
   // Let's get the location of our images
   QDir workingDirectory(QApplication::applicationFilePath());
   workingDirectory.cdUp();
   workingDirectory.cdUp();
   QString imagesDirectory = workingDirectory.absolutePath() + "/assets/";
   
   // Instantiate our images and put them in pixmaps
   std::vector<QImage> images;
   
   images.push_back(QImage(imagesDirectory + "4tb_Seagate_HardDrive.jpeg"));
   images.push_back(QImage(imagesDirectory + "2tb_WB_HardDrive.jpeg"));
   images.push_back(QImage(imagesDirectory + "250GBWDHardDrive.jpeg"));
   images.push_back(QImage(imagesDirectory + "1tb_WB_HardDrive.jpeg"));
   images.push_back(QImage(imagesDirectory + "1tb_Seagate_HardDrive.jpeg"));
   images.push_back(QImage(imagesDirectory + "500gb_WB_HardDrive.jpeg"));
   
   // Create the pixmaps and put them on the vector. Then set the images to the pixmap
   for (int i = 0; i < 6; ++i)
   {
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
   }
}
