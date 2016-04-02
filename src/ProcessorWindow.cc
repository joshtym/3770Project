#include <QtGui>
#include "ProcessorWindow.h"


ProcessorWindow::ProcessorWindow()
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
   specScrollAreas.clear();
   specCentralWidgets.clear();
   specLayouts.clear();
   
   // Load our assets
   loadAssets();
   
   // Instantiate all of our vectors and populate them
   for (int i = 0; i < 6; ++i)
   {
      boxOptions.push_back(new QCheckBox());
      expandableButtons.push_back(new QPushButton());
      itemPriceLabels.push_back(new QLabel());
      productImages.push_back(new QLabel());
      specWindows.push_back(new SpecificationWindow());
      specScrollAreas.push_back(new QScrollArea());
      specCentralWidgets.push_back(new QWidget());
      specLayouts.push_back(new QVBoxLayout());
      
      specCentralWidgets[i]->setLayout(specLayouts[i]);
      specScrollAreas[i]->setWidget(specCentralWidgets[i]);
      specScrollAreas[i]->setWidgetResizable(true);
      
      specWindows[i]->addWidget(specScrollAreas[i]);
      
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
      expandableButtons[i]->setText("View Now");
      expandableButtons[i]->setStyleSheet("text-align:right; border:0px;");
      boxOptions[i]->setMinimumWidth(200);
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
   
   /// TODO : Double the amount of layouts and add inner versions for specifications (Maybe reviews)?
   
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
   
   boxOptions[0]->setText("AMD FX-8350");
   boxOptions[1]->setText("AMD FX-6300");
   boxOptions[2]->setText("AMD Athlon X4");
   boxOptions[3]->setText("Intel Core i7-4790K");
   boxOptions[4]->setText("Intel Core i5-4690K");
   boxOptions[5]->setText("Intel Core i3-6100");
   
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

ProcessorWindow::~ProcessorWindow()
{
}

void ProcessorWindow::updateBoxOne(int newState)
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
            msgBox.setText("Did you look at your budget?");
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
            msgBox.setText("Did you look at your budget?");
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
      emit sendNewBoxUpdate(0, itemPrices[0], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxTwo(int newState)
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
            msgBox.setText("Did you look at your budget?");
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
            msgBox.setText("Did you look at your budget?");
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
      emit sendNewBoxUpdate(0, itemPrices[1], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxThree(int newState)
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
            msgBox.setText("Did you look at your budget?");
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
            msgBox.setText("Did you look at your budget?");
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
      emit sendNewBoxUpdate(0, itemPrices[2], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxFour(int newState)
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
            msgBox.setText("Did you look at your budget?");
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
            msgBox.setText("Did you look at your budget?");
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
      emit sendNewBoxUpdate(0, itemPrices[3], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxFive(int newState)
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
            msgBox.setText("Did you look at your budget?");
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
            msgBox.setText("Did you look at your budget?");
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
      emit sendNewBoxUpdate(0, itemPrices[4], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxSix(int newState)
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
            msgBox.setText("Did you look at your budget?");
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
            msgBox.setText("Did you look at your budget?");
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
      emit sendNewBoxUpdate(0, itemPrices[5], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::resizeEvent(QResizeEvent* resizeEvent)
{
   // Handle the resize of the window for the assets
   for (int i = 0; i < 6; ++i)
      if (!(pixMaps[i].isNull()))
         productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 6, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void ProcessorWindow::loadAssets()
{
   // Let's get the location of our images
   QDir workingDirectory(QApplication::applicationFilePath());
   workingDirectory.cdUp();
   workingDirectory.cdUp();
   QString imagesDirectory = workingDirectory.absolutePath() + "/assets/";
   
   // Instantiate our images and put them in pixmaps
   std::vector<QImage> images;
   
   images.push_back(QImage(imagesDirectory + "HighEndAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "HighEndIntelCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeIntelCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeIntelCpu.jpeg"));
   
   for (int i = 0; i < 6; ++i)
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
}

void ProcessorWindow::openWindowOne()
{
   specWindows[0]->setWindowTitle(boxOptions[0]->text());
   specWindows[0]->show();
   specWindows[0]->activateWindow();
}

void ProcessorWindow::openWindowTwo()
{
   specWindows[1]->setWindowTitle(boxOptions[1]->text());
   specWindows[1]->show();
   specWindows[1]->activateWindow();
}

void ProcessorWindow::openWindowThree()
{
   specWindows[2]->setWindowTitle(boxOptions[2]->text());
   specWindows[2]->show();
   specWindows[2]->activateWindow();
}

void ProcessorWindow::openWindowFour()
{
   specWindows[3]->setWindowTitle(boxOptions[3]->text());
   specWindows[3]->show();
   specWindows[3]->activateWindow();
}

void ProcessorWindow::openWindowFive()
{
   specWindows[4]->setWindowTitle(boxOptions[4]->text());
   specWindows[4]->show();
   specWindows[4]->activateWindow();
}

void ProcessorWindow::openWindowSix()
{
   specWindows[5]->setWindowTitle(boxOptions[5]->text());
   specWindows[5]->show();
   specWindows[5]->activateWindow();
}

void ProcessorWindow::loadSpecs()
{
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:25px\">AMD FX-8350 Black Edition Vishera 8-core 4.0 GHz</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Brand: AMD </p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Series: FX-Series</font>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Name: FX-8350 Black Edition</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     CPU Socket Type: Socket AM3+</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Core Name: Vishera</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Number of Cores: 8-Core</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Number of Threads: 8</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Operating Frequency: 4.0 GHz (4.2Ghz Turbo</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     L2 Cache: 4 x 2MB</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     L3 Cache: 8MB</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Manufacturing Tech: 32nm</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     64-Bit Support: Yes</p>"));
   specLayouts[0]->addWidget(new QLabel("<p style = \"font-size:15px\">     Thermal Design Power: 125W</p>"));
   
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:25px\">AMD FX-6300 Vishera 6-Core 3.5 GHz</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: AMD</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: FX-Series</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Name: FX-6300</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: Socket AM3+</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Core Name: Vishera</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Cores: 6-Core</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Threads: 6</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Operating Frequency: 3.5 GHz (4.1Ghz Turbo</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">L3 Cache: 8MB</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Manufacturing Tech: 32nm</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">64-Bit Support: Yes</p>"));
   specLayouts[1]->addWidget(new QLabel("<p style = \"font-size:15px\">Thermal Design Power: 95W</p>"));
   
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:25px\">AMD Athlon X4 860k</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: AMD</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Athlon X4</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Name: Athlon X4 860k</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: Socket FM2+</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Core Name: Kaveri</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Cores: Quad-Core</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Threads: 4</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Operating Frequency: 3.7 GHz</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Max Turbo Frequency: 4.0 GHz</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">L2 Cache: 2 x 2MB</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Manufacturing Tech: 28nm</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">64-Bit Support: Yes</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Integrated Memory Controller Speed: 2133 MHz</p>"));
   specLayouts[2]->addWidget(new QLabel("<p style = \"font-size:15px\">Thermal Design Power: 95W</p>"));
   
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:25px\">Intel Core i7-4790K Devil's Canyon Quad-Core</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: Intel</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Core i7</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Name: Core i7-4790K</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: LGA 1150</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Core Name: Devil's Canyon</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Cores: Quad-Core</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Threads: 8</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Operating Frequency: 4.0 GHz</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Max Turbo Frequency: 4.4 GHz</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">L2 Cache: 4 x 256KB</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">L3 Cache: 8MB</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Manufacturing Tech: 22nm</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">64-Bit Support: Yes</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Hyper-Threading Support: No</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Integrated Graphics: Intel HD Graphics 4600</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Graphics Base Frequency: 350 MHz</p>"));
   specLayouts[3]->addWidget(new QLabel("<p style = \"font-size:15px\">Graphics Max Dynamic Frequency: 1.25 GHz</p>"));
   
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:25px\">Intel Core i5-4690K Devil's Canyon Quad-Core</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: Intel</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Core i5</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Name: Core i5-4690K</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: LGA 1150</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Core Name: Devil's Canyon</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Cores: Quad-Core</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Threads: 4</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Operating Frequency: 3.5 GHz</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Max Turbo Frequency: 3.9 GHz</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">L2 Cache: 4 x 256KB</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">L3 Cache: 6MB</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Manufacturing Tech: 22nm</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">64-Bit Support: Yes</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Hyper-Threading Support: No</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Integrated Graphics: Intel HD Graphics 4600</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Graphics Base Frequency: 350 MHz</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Graphics Max Dynamic Frequency: 1.2 GHz</p>"));
   specLayouts[4]->addWidget(new QLabel("<p style = \"font-size:15px\">Thermal Design Power: 88W</p>"));
   
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:25px\">Intel Core i3-6100 3M 3.7 GHz</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Model</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Brand: Intel</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Series: Core i3</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Name: Core i3-6100</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">CPU Socket Type: LGA 1151</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:20px\"><b>Details</b></p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Core Name: Skylake</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Cores: Dual-Core</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Number of Threads: 4</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Operating Frequency: 3.7 GHz</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">L2 Cache: 2 x 256KB</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">L3 Cache: 3MB</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Manufacturing Tech: 14nm</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">64-Bit Support: Yes</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Hyper-Threading Support: Yes</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Integrated Graphics: Intel HD Graphics 530</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Graphics Max Dynamic Frequency: 1.05 GHz</p>"));
   specLayouts[5]->addWidget(new QLabel("<p style = \"font-size:15px\">Thermal Design Power: 65W</p>"));
}

void ProcessorWindow::updateCurrentAmount(double givenAmount)
{
   currentAmount = givenAmount;
}

void ProcessorWindow::updateBudgetAmount(double givenAmount)
{
   budgetAmount = givenAmount;
}



void ProcessorWindow::reset_selection()
{
   
   if (currentlyCheckedBox != -1)
   {

      boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);

   }
}
