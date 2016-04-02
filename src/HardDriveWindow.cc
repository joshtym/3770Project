#include <QtGui>
#include "HardDriveWindow.h"

HardDriveWindow::HardDriveWindow()
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
      specWindows.push_back(new SpecificationWindow());
      
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
   
   // Set our values
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
   
   boxOptions[0]->setText("Seagate 4TB Internal HDD");
   boxOptions[1]->setText("WD Red 2TB Internal HDD");
   boxOptions[2]->setText("WD Blue 1TB Internal HDD");
   boxOptions[3]->setText("Seagate Hybrid 1TB HDD");
   boxOptions[4]->setText("WD Blue 500GB Internal HDD");
   boxOptions[5]->setText("WD Blue 250GB Internal HDD");
   
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

HardDriveWindow::~HardDriveWindow()
{
}

void HardDriveWindow::updateBoxOne(int newState)
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

void HardDriveWindow::updateBoxTwo(int newState)
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

void HardDriveWindow::updateBoxThree(int newState)
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

void HardDriveWindow::updateBoxFour(int newState)
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

void HardDriveWindow::updateBoxFive(int newState)
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

void HardDriveWindow::updateBoxSix(int newState)
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

void HardDriveWindow::resizeEvent(QResizeEvent* resizeEvent)
{
   // Handle the resize of the window for the assets
   for (int i = 0; i < 6; ++i)
      if (!(pixMaps[i].isNull()))
         productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 6, Qt::KeepAspectRatio, Qt::SmoothTransformation));
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
   
   for (int i = 0; i < 6; ++i)
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
}

void HardDriveWindow::openWindowOne()
{
	specWindows[0]->setWindowTitle(boxOptions[0]->text());
	specWindows[0]->show();
	specWindows[0]->activateWindow();
}

void HardDriveWindow::openWindowTwo()
{
	specWindows[1]->setWindowTitle(boxOptions[1]->text());
	specWindows[1]->show();
	specWindows[1]->activateWindow();
}

void HardDriveWindow::openWindowThree()
{
	specWindows[2]->setWindowTitle(boxOptions[2]->text());
	specWindows[2]->show();
	specWindows[2]->activateWindow();
}

void HardDriveWindow::openWindowFour()
{
	specWindows[3]->setWindowTitle(boxOptions[3]->text());
	specWindows[3]->show();
	specWindows[3]->activateWindow();
}

void HardDriveWindow::openWindowFive()
{
	specWindows[4]->setWindowTitle(boxOptions[4]->text());
	specWindows[4]->show();
	specWindows[4]->activateWindow();
}

void HardDriveWindow::openWindowSix()
{
	specWindows[5]->setWindowTitle(boxOptions[5]->text());
	specWindows[5]->show();
	specWindows[5]->activateWindow();
}

void HardDriveWindow::updateCurrentAmount(double givenAmount)
{
   currentAmount = givenAmount;
}

void HardDriveWindow::updateBudgetAmount(double givenAmount)
{
   budgetAmount = givenAmount;
}

void HardDriveWindow::loadSpecs()
{
   specWindows[0]->addWidget(new QLabel("Seagate ST4000VN000"));
   specWindows[0]->addWidget(new QLabel("Model"));
   specWindows[0]->addWidget(new QLabel("Brand: Seagate"));
   specWindows[0]->addWidget(new QLabel("Series: NAS HDD"));
   specWindows[0]->addWidget(new QLabel("Performance"));
   specWindows[0]->addWidget(new QLabel("Interface: SATA 6.0Gb/s"));
   specWindows[0]->addWidget(new QLabel("Capacity: 4TB"));
   specWindows[0]->addWidget(new QLabel("Cache: 64MB"));
   specWindows[0]->addWidget(new QLabel("Form Factor: 3.5\""));
   
   specWindows[1]->addWidget(new QLabel("Western Digital WD20EFRX"));
   specWindows[1]->addWidget(new QLabel("Model"));
   specWindows[1]->addWidget(new QLabel("Brand: WD"));
   specWindows[1]->addWidget(new QLabel("Series: Red"));
   specWindows[1]->addWidget(new QLabel("Performance"));
   specWindows[1]->addWidget(new QLabel("Interface: SATA 6.0Gb/s"));
   specWindows[1]->addWidget(new QLabel("Capacity: 2TB"));
   specWindows[1]->addWidget(new QLabel("RPM: 5400 RPM"));
   specWindows[1]->addWidget(new QLabel("Cache: 64MB"));
   specWindows[1]->addWidget(new QLabel("Form Factor: 3.5\""));
   
   specWindows[2]->addWidget(new QLabel("Seagate ST1000DX001"));
   specWindows[2]->addWidget(new QLabel("Model"));
   specWindows[2]->addWidget(new QLabel("Brand: Seagate"));
   specWindows[2]->addWidget(new QLabel("Series: Desktop SSHD"));
   specWindows[2]->addWidget(new QLabel("Performance"));
   specWindows[2]->addWidget(new QLabel("Interface: SATA 6.0Gb/s"));
   specWindows[2]->addWidget(new QLabel("Capacity: 1TB"));
   specWindows[2]->addWidget(new QLabel("Flash Memory Capicity: 8GB"));
   specWindows[2]->addWidget(new QLabel("Cache: 64MB"));
   specWindows[2]->addWidget(new QLabel("Form Factor: 3.5\""));
   
   specWindows[3]->addWidget(new QLabel("Western Digital WD10JPVX"));
   specWindows[3]->addWidget(new QLabel("Model"));
   specWindows[3]->addWidget(new QLabel("Brand: WD"));
   specWindows[3]->addWidget(new QLabel("Series: Blue"));
   specWindows[3]->addWidget(new QLabel("Performance"));
   specWindows[3]->addWidget(new QLabel("Interface: SATA 6.0Gb/s"));
   specWindows[3]->addWidget(new QLabel("Capacity: 1TB"));
   specWindows[3]->addWidget(new QLabel("Cache: 8MB"));
   specWindows[3]->addWidget(new QLabel("RPM: 5400 RPM"));
   specWindows[3]->addWidget(new QLabel("Form Factor: 2.5\""));
   
   specWindows[4]->addWidget(new QLabel("Western Digital WD5000LPCX"));
   specWindows[4]->addWidget(new QLabel("Model"));
   specWindows[4]->addWidget(new QLabel("Brand: WD"));
   specWindows[4]->addWidget(new QLabel("Series: Blue"));
   specWindows[4]->addWidget(new QLabel("Performance"));
   specWindows[4]->addWidget(new QLabel("Interface: SATA 6.0Gb/s"));
   specWindows[4]->addWidget(new QLabel("Capacity: 500GB"));
   specWindows[4]->addWidget(new QLabel("Cache: 16MB"));
   specWindows[4]->addWidget(new QLabel("RPM: 5400 RPM"));
   specWindows[4]->addWidget(new QLabel("Form Factor: 2.5\""));
   
   specWindows[5]->addWidget(new QLabel("Western Digital WD2500AAKX"));
   specWindows[5]->addWidget(new QLabel("Model"));
   specWindows[5]->addWidget(new QLabel("Brand: WD"));
   specWindows[5]->addWidget(new QLabel("Series: Blue"));
   specWindows[5]->addWidget(new QLabel("Performance"));
   specWindows[5]->addWidget(new QLabel("Interface: SATA 6.0Gb/s"));
   specWindows[5]->addWidget(new QLabel("Capacity: 250GB"));
   specWindows[5]->addWidget(new QLabel("Cache: 16MB"));
   specWindows[5]->addWidget(new QLabel("RPM: 7200 RPM"));
   specWindows[5]->addWidget(new QLabel("Form Factor: 3.5\""));
}
