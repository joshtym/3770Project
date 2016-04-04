#include <QtGui>
#include "RamWindow.h"

RamWindow::RamWindow()
{
   initValues();
   loadSpecs();
   loadAssets();
   initVectorValues();
}

RamWindow::~RamWindow()
{
}

void RamWindow::initVectorValues()
{
   // Set our price labels and prices
   itemPriceLabels[0]->setText("$219.99");
   itemPrices.push_back(219.99);
   itemPriceLabels[1]->setText("$129.99");
   itemPrices.push_back(129.99);
   itemPriceLabels[2]->setText("$69.00");
   itemPrices.push_back(69.99);
   itemPriceLabels[3]->setText("$239.99");
   itemPrices.push_back(239.99);
   itemPriceLabels[4]->setText("$102.99");
   itemPrices.push_back(102.99);
   itemPriceLabels[5]->setText("$69.99");
   itemPrices.push_back(69.99);
   
   // Set our check box values
   boxOptions[0]->setText("G.SKILL RipJaws X Series (4 x 8GB)");
   boxOptions[1]->setText("G.SKILL RipJaws X Series (2 x 8GB)");
   boxOptions[2]->setText("G.SKILL RipJaws X Series (2 x 4GB)");
   boxOptions[3]->setText("Corsair Vengeance (4 x 8GB)");
   boxOptions[4]->setText("Corsair Vengeance (2 x 8GB)");
   boxOptions[5]->setText("Corsair Vengeance (2 x 4GB)");
   
   // Set our minimum width
   for (int i = 0; i < 6; ++i)
      boxOptions[i]->setMinimumWidth(300);
}

void RamWindow::loadSpecs()
{
   // Hard Code all of our details (Ideally, you'd use a web scraper or something)
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:25px\">G.SKILL F3-2400C11Q-32GXM</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: G.SKILL</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Ripjaws X Series</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 32GB (4 x 8GB)</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Type: 240-pin DDR3 SDRAM</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Speed: DDR3 2400 (PC3 19200)</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Cas Latency: 11</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Timing: 11-13-13-31</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Voltage: 1.65V</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Multi-chanel Kit: Dual / Quad Channel Kit</p>"));
   
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:25px\">G.SKILL F3-1600C9D-16GXM</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: G.SKILL</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Ripjaws X Series</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 16GB (2 x 8GB)</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Type: 240-pin DDR3 SDRAM</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Speed: DDR3 1600 (PC3 12800)</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Cas Latency: 9</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Timing: 9-9-9-24</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Voltage: 1.5V</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Multi-chanel Kit: Dual Channel Kit</p>"));
   
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:25px\">G.SKILL F3-12800CL9D-8GBXL</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: G.SKILL</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Ripjaws X Series</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 8GB (2 x 4GB)</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Type: 240-pin DDR3 SDRAM</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Speed: DDR3 1600 (PC3 12800)</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Cas Latency: 9</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Timing: 9-9-9-24</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Voltage: 1.5V</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Multi-chanel Kit: Dual Channel Kit</p>"));
   
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:25px\">Corsair CMZ32GX3M4X1866C10</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: CORSAIR</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Vengeance</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 32GB (4 x 8GB)</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Type: 240-pin DDR3 SDRAM</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Speed: DDR3 1866 (PC3 14900)</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Cas Latency: 10</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Timing: 10-11-10-30</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Voltage: 1.5V</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Multi-chanel Kit: Quad Channel Kit</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Heat Spreader: Yes</p>"));
   
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:25px\">Corsair CMZ16GX3M2A1600C9</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: CORSAIR</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Vengeance</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 16GB (2 x 8GB)</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Type: 240-pin DDR3 SDRAM</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Speed: DDR3 1600 (PC3 12800)</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Cas Latency: 9</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Timing: 9-9-9-24</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Voltage: 1.5V</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Multi-chanel Kit: Dual Channel Kit</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Heat Spreader: Yes</p>"));
   
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:25px\">Corsair CML8GX3M2A1600C9</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: CORSAIR</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Vengeance LP</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Capacity: 8GB (2 x 4GB)</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Type: 240-pin DDR3 SDRAM</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Speed: DDR3 1600 (PC3 12800)</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Cas Latency: 9</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Timing: 9-9-9-24</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Voltage: 1.5V</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Multi-chanel Kit: Dual / Quad Channel Kit</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Heat Spreader: Yes</p>"));
}

void RamWindow::loadAssets()
{
   // Let's get the location of our images
   QDir workingDirectory(QApplication::applicationFilePath());
   workingDirectory.cdUp();
   workingDirectory.cdUp();
   QString imagesDirectory = workingDirectory.absolutePath() + "/assets/";
   
   // Instantiate our images and put them in pixmaps
   std::vector<QImage> images;
   
   images.push_back(QImage(imagesDirectory + "HighEndAmdMobo.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeAmdMobo.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeAmdMobo.jpeg"));
   images.push_back(QImage(imagesDirectory + "HighEndIntelMobo.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeIntelMobo.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeIntelMobo.jpeg"));
   
   // Create the pixmaps and put them on the vector. Then set the images to the pixmap
   for (int i = 0; i < 6; ++i)
   {
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
   }
}
