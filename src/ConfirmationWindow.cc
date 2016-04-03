#include <QtGui>
#include "ConfirmationWindow.h"

ConfirmationWindow::ConfirmationWindow()
{
   // Variable declarations
   QVBoxLayout* mainLayout = new QVBoxLayout();
   QHBoxLayout* innerLayout = new QHBoxLayout();
   QHBoxLayout* buttonLayout = new QHBoxLayout();
   QVBoxLayout* leftLayout = new QVBoxLayout();
   QVBoxLayout* rightLayout = new QVBoxLayout();
   QPushButton* confirmationButton = new QPushButton("Confirm");
   QPushButton* dudButtonOne = new QPushButton();
   QPushButton* dudButtonTwo = new QPushButton();
   
   // Variable instantiations
   budgetAmount = 0;
   currentAmount = 0;
   
   // Ensure empty vectors
   currentlySelectedObjects.clear();
   currentlySelectedObjectPrices.clear();
   
   currentlySelectedObjects.push_back(new QLabel("No CPU Selected."));
   currentlySelectedObjects.push_back(new QLabel("No Motherboard Selected"));
   currentlySelectedObjects.push_back(new QLabel("NO RAM Selected"));
   currentlySelectedObjects.push_back(new QLabel("No HDD Selected"));
   currentlySelectedObjects.push_back(new QLabel("Current Budget Amount"));
   currentlySelectedObjects.push_back(new QLabel("Cost"));
   
   // Add some more details
   for (int i = 0; i < 4; ++i)
      currentlySelectedObjectPrices.push_back(new QLabel("$0"));
   
   currentlySelectedObjectPrices.push_back(new QLabel("$" + QString::number(budgetAmount)));
   currentlySelectedObjectPrices.push_back(new QLabel("$" + QString::number(currentAmount)));
   
   // Set fixed size for our button
   confirmationButton->setFixedHeight(25);
   confirmationButton->setFixedWidth(100);
   dudButtonOne->setStyleSheet("border:0px;");
   dudButtonTwo->setStyleSheet("border:0px;");
   dudButtonOne->setEnabled(false);
   dudButtonTwo->setEnabled(false);
   buttonLayout->addWidget(dudButtonOne);
   buttonLayout->addWidget(confirmationButton);
   buttonLayout->addWidget(dudButtonTwo);
   
   for (int i = 0; i < 6; ++i)
   {
      if (i < 4)
	 currentlySelectedObjectPrices.push_back(new QLabel("$0"));
      
      leftLayout->addWidget(currentlySelectedObjects[i]);
      rightLayout->addWidget(currentlySelectedObjectPrices[i]);
   }
   
   // Finish our layout management
   innerLayout->addLayout(leftLayout);
   innerLayout->addLayout(rightLayout);
   mainLayout->addLayout(innerLayout);
   mainLayout->addLayout(buttonLayout);
   this->setLayout(mainLayout);
   
   // Create a connection
   connect(confirmationButton, SIGNAL(clicked()), this, SLOT(confirmPurchase()));
}

ConfirmationWindow::~ConfirmationWindow()
{
}

void ConfirmationWindow::updateBudgetAmount(double givenBudget)
{
   budgetAmount = givenBudget;
   
   if (givenBudget == 10000000000)
      currentlySelectedObjectPrices[4]->setText("No Budget!");
   else
      currentlySelectedObjectPrices[4]->setText("$" + QString::number(budgetAmount));
}

void ConfirmationWindow::updateCurrentAmount(double givenAmount)
{
   currentAmount = givenAmount;
   currentlySelectedObjectPrices[5]->setText("$" + QString::number(currentAmount));
}

void ConfirmationWindow::updateVectors(QString newName, double newAmount, int indexNumber)
{
   switch(indexNumber)
   {
      case -1:
	 resetValues();
	 break;
      case 0:
      {
	 if (newName == "AMD Processor" || newName == "Intel Processor")
	    currentlySelectedObjects[0]->setText("No CPU Selected");
	 else
	    currentlySelectedObjects[0]->setText(newName);
	 currentlySelectedObjectPrices[0]->setText("$" + QString::number(newAmount));
	 break;
      }
      case 1:
      {
	 if (newName == "AMD Motherboard" || newName == "Intel Motherboard")
	    currentlySelectedObjects[1]->setText("No Motherboard Selected");
	 else
	    currentlySelectedObjects[1]->setText(newName);
	 currentlySelectedObjectPrices[1]->setText("$" + QString::number(newAmount));
	 break;
      }
      case 2:
      {
	 if (newName == "")
	    currentlySelectedObjects[2]->setText("No RAM Selected");
	 else
	    currentlySelectedObjects[2]->setText(newName);
	 currentlySelectedObjectPrices[2]->setText("$" + QString::number(newAmount));
	 break;
      }
      case 3:
      {
	 if (newName == "")
	    currentlySelectedObjects[3]->setText("No HDD Selected");
	 else
	    currentlySelectedObjects[3]->setText(newName);
	 currentlySelectedObjectPrices[3]->setText("$" + QString::number(newAmount));
	 break;
      }
      case 4:
	 resetValues();
	 break;
   }
}

void ConfirmationWindow::confirmPurchase()
{
   int optionSelected;
   
   if (currentAmount == 0)
   {
      QMessageBox msgBox;
      msgBox.setText("You have not selected anything for purchase!");
      msgBox.exec();
   }
   else
   {
      QMessageBox msgBox;
   
      msgBox.setText("Confirm Purchase of Parts");
      msgBox.setInformativeText("This will place your order to FakeCompany. Are you sure?");
      msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
      msgBox.setDefaultButton(QMessageBox::Cancel);
      optionSelected = msgBox.exec();
   
      if (optionSelected == QMessageBox::Ok)
	 emit sendReset();
   }
}

void ConfirmationWindow::resetValues()
{
   currentlySelectedObjects[0]->setText("No CPU Selected.");
   currentlySelectedObjects[1]->setText("No Motherboard Selected.");
   currentlySelectedObjects[2]->setText("No RAM Selected.");
   currentlySelectedObjects[3]->setText("No HDD Selected.");
   
   for (int i = 0; i < 4; ++i)
      currentlySelectedObjectPrices[i]->setText("$0");
}
