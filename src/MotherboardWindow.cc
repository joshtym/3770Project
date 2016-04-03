#include <QtGui>
#include <iostream>
#include "MotherboardWindow.h"

MotherboardWindow::MotherboardWindow()
{
   // The main layout
   QVBoxLayout* mainLayout = new QVBoxLayout();
   
   // Variable instantiations
   currentlyCheckedBox = -1;
   currentAmount = 0;
   budgetAmount = 0;
   
   // Ensure a starting empty vector
   layouts.clear();
   boxOptions.clear();
   expandableButtons.clear();
   itemPriceLabels.clear();
   itemPrices.clear();
   productImages.clear();
   pixMaps.clear();
   specWindows.clear();
   
   // Load our assets
   loadAssets();
   
   // Instantiate all of our vectors and populate them
   for (int i = 0; i < 6; ++i)
   {
      boxOptions.push_back(new QCheckBox());
      expandableButtons.push_back(new QPushButton());
      itemPriceLabels.push_back(new QLabel());
      productImages.push_back(new QLabel());
      specWindows.push_back(new SpecificationWindow(this));
      specScrollAreas.push_back(new QScrollArea());
      specCentralWidgets.push_back(new QWidget());
      specLayouts.push_back(new QVBoxLayout());
      
      specCentralWidgets[i]->setLayout(specLayouts[i]);
      specScrollAreas[i]->setWidget(specCentralWidgets[i]);
      specScrollAreas[i]->setWidgetResizable(true);
      
      specWindows[i]->addWidget(specScrollAreas[i]);
      
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
      expandableButtons[i]->setText("More Info");
      expandableButtons[i]->setStyleSheet("text-align:right; border:0px;");
      boxOptions[i]->setMinimumWidth(325);
      itemPriceLabels[i]->setMinimumWidth(125);
   }
   
   // Load specs
   loadSpecs();
   
   // Make our layouts. Odd layouts not initially visible since widgets hidden
   for (int i = 0; i < 6; ++i)
   {
      layouts.push_back(new QHBoxLayout());
      layouts[i]->addWidget(productImages[i]);
      layouts[i]->addWidget(boxOptions[i]);
      layouts[i]->addWidget(itemPriceLabels[i]);
      layouts[i]->addWidget(expandableButtons[i]);
         
      mainLayout->addLayout(layouts[i]);
   }
   
   // Set our values
   itemPriceLabels[0]->setText("$259.99");
   itemPrices.push_back(259.99);
   itemPriceLabels[1]->setText("$159.99");
   itemPrices.push_back(159.99);
   itemPriceLabels[2]->setText("$109.99");
   itemPrices.push_back(109.99);
   itemPriceLabels[3]->setText("$499.99");
   itemPrices.push_back(499.99);
   itemPriceLabels[4]->setText("$339.99");
   itemPrices.push_back(339.99);
   itemPriceLabels[5]->setText("$179.99");
   itemPrices.push_back(179.99);
   
   boxOptions[0]->setText("MSI Gaming 990FX-A AMD Motherboard");
   boxOptions[1]->setText("ASUS m5A97 AMD Motherboard");
   boxOptions[2]->setText("Gigabyte Micro ATX AMD Motherboard");
   boxOptions[3]->setText("MSI Gaming Z97 ATX Intel Motherboard");
   boxOptions[4]->setText("ASRock H97M Micro ATX Intel Motherboard");
   boxOptions[5]->setText("ASRock H81M Mini ITX Intel Motherboard");
   
   this->setLayout(mainLayout);
   
   // Connect our check boxes
   connect(boxOptions[0], SIGNAL(stateChanged(int)), this, SLOT(updateBoxOne(int)));
   connect(boxOptions[1], SIGNAL(stateChanged(int)), this, SLOT(updateBoxTwo(int)));
   connect(boxOptions[2], SIGNAL(stateChanged(int)), this, SLOT(updateBoxThree(int)));
   connect(boxOptions[3], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFour(int)));
   connect(boxOptions[4], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFive(int)));
   connect(boxOptions[5], SIGNAL(stateChanged(int)), this, SLOT(updateBoxSix(int)));
   
   // Connect our expandable buttons
   connect(expandableButtons[0], SIGNAL(clicked()), this, SLOT(openWindowOne()));
   connect(expandableButtons[1], SIGNAL(clicked()), this, SLOT(openWindowTwo()));
   connect(expandableButtons[2], SIGNAL(clicked()), this, SLOT(openWindowThree()));
   connect(expandableButtons[3], SIGNAL(clicked()), this, SLOT(openWindowFour()));
   connect(expandableButtons[4], SIGNAL(clicked()), this, SLOT(openWindowFive()));
   connect(expandableButtons[5], SIGNAL(clicked()), this, SLOT(openWindowSix()));
}

MotherboardWindow::~MotherboardWindow()
{
}

void MotherboardWindow::updateBoxOne(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[0]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
            boxOptions[0]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
            currentlyCheckedBox = 0;
         }
      }
      else if (currentlyCheckedBox != 0)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[0]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
            boxOptions[0]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
            currentlyCheckedBox = 0;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[0], "AMD Motherboard");
      currentlyCheckedBox = -1;
   }
}

void MotherboardWindow::updateBoxTwo(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[1]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
            boxOptions[1]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
            currentlyCheckedBox = 1;
         }
      }
      else if (currentlyCheckedBox != 1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[1]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
            boxOptions[1]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
            currentlyCheckedBox = 1;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[1], "AMD Motherboard");
      currentlyCheckedBox = -1;
   }
}

void MotherboardWindow::updateBoxThree(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[2]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
            boxOptions[2]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
            currentlyCheckedBox = 2;
         }
      }
      else if (currentlyCheckedBox != 2)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[2]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
            boxOptions[2]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
            currentlyCheckedBox = 2;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[2], "AMD Motherboard");
      currentlyCheckedBox = -1;
   }
}

void MotherboardWindow::updateBoxFour(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[3]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
            boxOptions[3]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
            currentlyCheckedBox = 3;
         }
      }
      else if (currentlyCheckedBox != 3)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[3]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
            boxOptions[3]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
            currentlyCheckedBox = 3;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[3], "Intel Motherboard");
      currentlyCheckedBox = -1;
   }
}

void MotherboardWindow::updateBoxFive(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[4]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
            boxOptions[4]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
            currentlyCheckedBox = 4;
         }
      }
      else if (currentlyCheckedBox != 4)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[4]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
            boxOptions[4]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
            currentlyCheckedBox = 4;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[4], "Intel Motherboard");
      currentlyCheckedBox = -1;
   }
}

void MotherboardWindow::updateBoxSix(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[5]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
            boxOptions[5]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
            currentlyCheckedBox = 5;
         }
      }
      else if (currentlyCheckedBox != 0)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[5]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Item cannot fit into budget.");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
            boxOptions[5]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
            currentlyCheckedBox = 5;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[5], "Intel Motherboard");
      currentlyCheckedBox = -1;
   }
}

void MotherboardWindow::resizeEvent(QResizeEvent* resizeEvent)
{
   // Handle the resize of the window for the assets
   for (int i = 0; i < 6; ++i)
      if (!(pixMaps[i].isNull()))
         productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 6, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MotherboardWindow::loadAssets()
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
   
   for (int i = 0; i < 6; ++i)
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
}

void MotherboardWindow::openWindowOne()
{
	specWindows[0]->setWindowTitle(boxOptions[0]->text());
	specWindows[0]->show();
	specWindows[0]->activateWindow();
}

void MotherboardWindow::openWindowTwo()
{
	specWindows[1]->setWindowTitle(boxOptions[1]->text());
	specWindows[1]->show();
	specWindows[1]->activateWindow();
}

void MotherboardWindow::openWindowThree()
{
	specWindows[2]->setWindowTitle(boxOptions[2]->text());
	specWindows[2]->show();
	specWindows[2]->activateWindow();
}

void MotherboardWindow::openWindowFour()
{
	specWindows[3]->setWindowTitle(boxOptions[3]->text());
	specWindows[3]->show();
	specWindows[3]->activateWindow();
}

void MotherboardWindow::openWindowFive()
{
	specWindows[4]->setWindowTitle(boxOptions[4]->text());
	specWindows[4]->show();
	specWindows[4]->activateWindow();
}

void MotherboardWindow::openWindowSix()
{
	specWindows[5]->setWindowTitle(boxOptions[5]->text());
	specWindows[5]->show();
	specWindows[5]->activateWindow();
}

void MotherboardWindow::updateCurrentAmount(double givenAmount)
{
   currentAmount = givenAmount;
}

void MotherboardWindow::updateBudgetAmount(double givenAmount)
{
   budgetAmount = givenAmount;
}

void MotherboardWindow::loadSpecs()
{
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:25px\">MSI Gaming 990FXA-GAMING AMD Motherboard</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: MSI</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: MSI Gaming</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Model: 990FXA-GAMING</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Supported CPU</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: AM3+/AM3</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Type: AMD FX / Phenom II / Athlon II and Sempron</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Chipset: AMD 990FX & SB950</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Memory</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Memory Slots: 4x240pin</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Memory Standard: DDR3 2133(OC)/ 1866/ 1600/ 1333/ 1066</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Maximum Memory Supported: 32GB</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Channel Supported: Dual Channel</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Expansion Slots</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express 2.0 x 16: 3 x PCIe 2.0 x 16 slots</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express x1: 2 x PCIe 2.0 x1 slots</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Slots: 1 x PCI Slot</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Storage Devices</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA 6Gb/s: 6xSATA 6Gb/s</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA RAID: 0/1/5/10</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard LAN</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">LAN Chipset: Killer E2205 Gigabit LAN controller</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Max LAN Speed: 10/100/1000Mbps</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Rear Panel Ports</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">PS/2: 1 x PS/2 Keyboard / Mouse Port</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">RJ45: 1 x RJ45</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 3.1: 2 x USB 3.1</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 1.1/2.0: 8 x USB 2.0</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">S/PDIIF Out: 1 x Optical</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Ports: 6 x OFC audio jacks</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Internal I/O Connectors </b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Onboard USB: 3 x USB 2.0 connectors, 1 x USB 3.0 connector</p>"));
   QLabel* S0 = new QLabel("<p style = \"font-size:15px\">Other connectors: 1 x 24-pin ATX maiin power connector, 1 x 8-pin ATX 12V power connector, 1 x 4-pin CPU fan connector, 2 x 4-pin system fan connectors, 2 x 3-pin system fan connectors, 1 x Front panel audio connector, 2 x Front panel connectors, 1 x Chassis Intrusion connector, 1 x TPM module connector, 1 x Serial port connector, 1 x S/PDIF-Out connector, 1 x Clear CMOS jumper, 1 x Slow mod booting switch</p>");
   S0->setWordWrap(true);
   specLayouts[0]->addWidget(S0);
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Physical Specifications </b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: ATX</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Dimensions (W x L): 12.0\" x 9.6\"</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">Power Pin: 24 Pin</p>"));
   
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:25px\">ASUS M5a97 R2.0 ATX AMD Motherboard</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: ASUS</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Model: M5A97 R2.0</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Supported CPU</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: AM3+</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Type: AMD FX / Phenom II / Athlon II and Sempron 100 Series</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">FSB: 2400 MHz Hyper Transport (4800 MT/s)</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Chipset: AMD 970 + SB 950</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Memory</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Memory Slots: 4x240pin</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Memory Standard: DDR3 2133(OC)/ 1866/ 1600/ 1333/ 1066</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Maximum Memory Supported: 32GB</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Channel Supported: Dual Channel</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Expansion Slots</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express 2.0 x 16: 1 x PCIe 2.0 x 16 (blue), 1 x PCIe 2.0 x16 (x4 mode, black)</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express x1: 2 x PCIe 2.0 x 1 slots</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Slots:21 x PCI Slot</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Storage Devices</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA 6Gb/s: 6xSATA 6Gb/s Ports</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA RAID: 0/1/5/10</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard Audio </b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Chipset: Realtek ALC887</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Channels: 8 Channels</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard LAN</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">LAN Chipset: Realtek 8111F</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Max LAN Speed: 10/100/1000Mbps</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Rear Panel Ports</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">PS/2: 1 x PS/2 Keyboard, 1 x PS/2 Mouse</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">RJ45: 1 x LAN (RJ45) port</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 3.0: 2 x USB 3.0</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 1.1/2.0: 6 x USB 2.0</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Ports: 6 Ports</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Internal I/O Connectors </b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Onboard USB: 3 x USB 2.0 connectors, 1 x USB 3.0 connector</p>"));
   
   QLabel* S1 = new QLabel;
   S1->setText("Other Connectors: 1 x TPM connector, 1 x COM port connector, 1 x CPU Fan connector, 3 x Chassis Fan connectors, 1 x S/PDIF out header, 1 x 24-pin EATX Power connector, 1 x 8-pin ATX 12V Power connector, 1 x Front panel audio connector, 1 x Sytem panel, 1 x DirectKey Button, 1 x DRCT header, 1 x MemOK! button, 1 x Clear CMOS jumper, 1 x USB BIOS Flashback button</p>");
S1->setWordWrap(true);
specLayouts[1]->addWidget(S1);
   
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Physical Specifications </b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: ATX</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Dimensions (W x L): 12.0\" x 9.6\"</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Power Pin: 24 Pin</p>"));
   
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:25px\">Gigabyte GA-78LMT ATX AMD Motherboard</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: GigaByte</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Model: GA-78LMT-USB3 (rev 6.0)</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Supported CPU</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: AM3+</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Type: AM3+ / Phenom II / Athlon II processor</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">FSB: 2200 MHz Hyper Transport (4400 MT/s)</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Chipset: AMD 760G + SB 710</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Memory</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Memory Slots: 4x240pin</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Memory Standard: DDR3 1600(O.C)/ 1333/ 1066</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Maximum Memory Supported: 32GB</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Channel Supported: Dual Channel</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Expansion Slots</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express 2.0 x 16: 1 x PCIe 2.0 x 16 </p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express x1: 1 x PCI Express x 1 slots</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Slots:2 x PCI Slot</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Storage Devices</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">PATA: 1 x ATA133 2 Dev. Max</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA 3Gb/s: 6xSATA 3Gb/s Ports</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA RAID: 0/1/10/JBOD</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard Audio </b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Chipset: Realtek ALC892</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Channels: 2/4/5.1/7.1-channel</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard LAN</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">LAN Chipset: Realtek GbE LAN chip</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Max LAN Speed: 10/100/1000Mbps</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Rear Panel Ports</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">PS/2: 1 x PS/2 Keyboard / Mouse port</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Video Ports: 1 x D-Sub port, 1 x DVI-D port</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">HDMI: 1 x HDMI</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">RJ45: 1 x LAN (RJ45) port</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 3.0: 2 x USB 3.0/2.0 ports</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 1.1/2.0: 4 x USB 2.0/1.1 ports</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Ports: 3 x audio jacks</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Internal I/O Connectors </b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Onboard USB: 3 x USB 2.0 connectors, 1 x USB 3.0 connector</p>"));
 
   QLabel* S2 = new QLabel("<p style = \"font-size:15px\">Other Connectors: 1 x 24-pin ATX main power connector, 1 x 8-pin ATX 12V power connector, 1 x CPU fan header, 1 x system fan header, 1 x front header, 1 x front panel audio header, 1 x S/PDIF Out header, 1 x serial port header, 1 x parallel port header, 1 x Clear CMOS jumper</p>");
   S2->setWordWrap(true);
   specLayouts[2]->addWidget(S2);
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Physical Specifications </b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: Micro ATX</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Dimensions (W x L): 9.6\" x 9.6\"</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Power Pin: 24 Pin</p>"));
   
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:25px\">MSI Z97 GAMING 5</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: MSI</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: MSI Gaming</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Model: Z97 GAMING 5</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Supported CPU</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: LGA 1150</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Type: Core i7 / i5 / i3 / Pentium / Celeron</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Chipset: Intel Z97</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Memory</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Memory Slots: 4x240pin</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Memory Standard: DDR3 3300*(*OC)/ 3200*/ 3100*/ 3000*/ 2800*/ 2666*/ 2600*/ 2400*/ 2200*/ 2133*/ 2000*/ 1866*/ 1600/ 1333/ 1066</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Maximum Memory Supported: 32GB</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Channel Supported: Dual Channel</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Expansion Slots</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express 3.0 x 16: 3 x PCIe 3.0 x 16 </p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">M.2: 1xM.2 port</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express x1: 4 x PCI PCIe 2.0 x 1 slots</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Storage Devices</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA 6Gb/s: 6xSATA 6Gb/s Ports</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA RAID: 0/1/5/10</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard Audio </b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Chipset: Realtek ALC1150</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Channels: 7.1-Channels</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard LAN</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">LAN Chipset: Killer E2205</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Max LAN Speed: 10/100/1000Mbps</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Rear Panel Ports</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">PS/2: 1 x PS/2 Keyboard / Mouse port</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Video Ports: 1 x VGA port, 1 x DVI-D port</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">HDMI: 1 x HDMI</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">RJ45: 1 x LAN (RJ45) port</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 3.0: 4 x USB 3.0</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 1.1/2.0: 4 x USB 2.0 ports</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Ports: 6 x OFC audio jacks</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Internal I/O Connectors </b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Onboard USB: 2 x USB 2.0 connectors, 1 x USB 3.0 connector</p>"));
   QLabel* S3 =new QLabel("<p style = \"font-size:15px\">Other Connectors: 1 x 24-pin ATX main power connector, 1 x 8-pin ATX 12V power connector, 2 x 4-pin CPU fan connectors, 3 x 4-pin system fan connectors, 1 x TPM module connector, 1 x Serial port connector, 1 x Front panel audio connector, 1 x Direct audio power connector, 2 x System panel connectors, 1 x Chassis Intrusion connector, 1 x Clear CMOS jumper, 1 x Audio power switch, 1 x 2-Digit Debug Code LED</p>");
   S3->setWordWrap(true);
   specLayouts[3]->addWidget(S3);
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Physical Specifications </b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: ATX</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Dimensions (W x L): 12.0\" x 9.6\"</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Power Pin: 24 Pin</p>"));
   
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:25px\">ASRock</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: ASRock</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Model: H97M Pro4</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\"><b>Supported CPU</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: LGA 1150</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Type: Core i7 / i5 / i3 / Pentium / Celeron</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Chipset: Intel H97</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Memory</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Memory Slots: 4x240pin</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Memory Standard: DDR3/DDR3L 1600/ 1333/ 1066</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Maximum Memory Supported: 32GB</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Channel Supported: Dual Channel</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Expansion Slots</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express 3.0 x 16: 1 x PCIe 3.0 x 16</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express 2.0 x 16: 1 x PCIe 2.0 x 16</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Slots: 2 x PCI Slots</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Storage Devices</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA 6Gb/s: 6xSATA 6Gb/s Ports</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA RAID: 0/1/5/10</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Onboard Video: Intel HD Graphics</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard Audio </b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Chipset: Realtek ALC892</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Channels: 7.1-Channels</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard LAN</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">LAN Chipset: Intel l218V</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Max LAN Speed: 10/100/1000Mbps</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Rear Panel Ports</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">PS/2: 1 x PS/2 Keyboard / Mouse port</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Video Ports: 1 x D-Sub port, 1 x DVI-D port</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">HDMI: 1 x HDMI</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">RJ45: 1 x LAN (RJ45) port</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 3.0: 4 x USB 3.0</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 1.1/2.0: 2 x USB 2.0 ports</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Ports: HD Audio Jacks: Rear, Central, Bass, Line in, Front Speaker, Microphone</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Internal I/O Connectors </b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Onboard USB: 2 x USB 2.0 connectors, 1 x USB 3.0 connector</p>"));
   QLabel* S4 = new QLabel("<p style = \"font-size:15px\">Other Connectors: 1 x Print Port Header, 1 x COM Port Header, 1 x Chassis Intrusion Header, 1 x TPM Header, 2 x CPU Fan Connectors (1 x 4-pin, 1 x 3-pin), 2 x Chassis Fan Connectors (1 x 4-pin, 1 x 3-pin), 1 x Power Fan Connector (3-pin), 1 x 24-pin ATX Power Connector, 1 x 8-pin 12V Power Connector, 1 x Front Panel Audio Connector, 1 x Thunderbolt AIC Connector*</p>");
   S4->setWordWrap(true);
   specLayouts[4]->addWidget(S4);
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Physical Specifications </b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: Micro ATX</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Power Pin: 24 Pin</p>"));
   
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:25px\">ASRock H81M-ITX LGA 1150 Mini ITX Motherboard</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: ASRock</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Model: H81M-ITX</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Supported CPU</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: LGA 1150</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Type: Core i7 / i5 / i3 / Pentium / Celeron</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Chipset: Intel H81</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Memory</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Memory Slots: 2x240pin</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Memory Standard: DDR3 1600/1333/1066</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Maximum Memory Supported: 16GB</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Channel Supported: Dual Channel</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Expansion Slots</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">PCI Express 2.0 x 16: 1 x PCIe 3.0 x 16 </p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Storage Devices</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">SATA 6Gb/s: 2xSATA 6Gb/s Ports</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard Audio </b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Chipset: Realtek ALC892</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Channels: 7.1-Channels</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Onboard LAN</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">LAN Chipset: Qualcomm Atheros AR8171</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Max LAN Speed: 10/100/1000Mbps</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Rear Panel Ports</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">PS/2: 1 x PS/2 Keyboard / Mouse port</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Video Ports: 1 x D-Sub port, 1 x DVI-D port</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">HDMI: 1 x HDMI</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 3.0: 2 x USB 3.0</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">USB 1.1/2.0: 4 x USB 2.0 ports</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Audio Ports: 6 x OFC audio jacks</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">eSATA: 1 x eSATA</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Internal I/O Connectors </b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Onboard USB: 2 x USB 2.0 connectors</p>"));
   QLabel* S5 = new QLabel("<p style = \"font-size:15px\">Other Connectors: 1 x Chassis Intrusion Header, 1 x TPM Header, 1 x CPU Fan Connector (4-pin), 1 x Chassis Fan Connector (4-pin), 1 x 24 pin ATX Power Connector, 1 x 4 pin 12V Power Connector, 1 x Front Panel Audio Connector </p>");
   S5->setWordWrap(true);
   specLayouts[5]->addWidget(S5);
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b> Physical Specifications </b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Form Factor: Mini ITX</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Power Pin: 24 Pin</p>"));
}

void MotherboardWindow::reset_selection()
{
   if (currentlyCheckedBox != -1)
      boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
}

void MotherboardWindow::updateAvailableOptions(QString type, bool disable)
{
   if (!(disable))
      for (int i = 0; i < 6; ++i)
         boxOptions[i]->setEnabled(true); 
	else
		for (int  i = 0; i < 6; ++i)
			if (!(boxOptions[i]->text().contains(type)))
            boxOptions[i]->setEnabled(false);
}
