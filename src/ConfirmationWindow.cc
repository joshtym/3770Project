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
   
   // Load up our vectors
   for (int i = 0; i < 4; ++i)
   {
      currentlySelectedObjects.push_back(new QLabel("No item selected!"));
      currentlySelectedObjectPrices.push_back(new QLabel("$0"));
      leftLayout->addWidget(currentlySelectedObjects[i]);
      rightLayout->addWidget(currentlySelectedObjectPrices[i]);
   }
   
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
   
   // Add some more details
   currentlySelectedObjects.push_back(new QLabel("Current Budget Amount"));
   currentlySelectedObjects.push_back(new QLabel("Cost"));
   currentlySelectedObjectPrices.push_back(new QLabel("$" + QString::number(budgetAmount)));
   currentlySelectedObjectPrices.push_back(new QLabel("$" + QString::number(currentAmount)));
   leftLayout->addWidget(currentlySelectedObjects[4]);
   rightLayout->addWidget(currentlySelectedObjectPrices[4]);
   leftLayout->addWidget(currentlySelectedObjects[5]);
   rightLayout->addWidget(currentlySelectedObjectPrices[5]);
   
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
   if (indexNumber >= 0 && indexNumber != 4)
   {
      if (newName == "")
	 currentlySelectedObjects[indexNumber]->setText("No item selected!");
      else
	 currentlySelectedObjects[indexNumber]->setText(newName);
	 
      currentlySelectedObjectPrices[indexNumber]->setText("$" + QString::number(newAmount));
   }
   else
   {
      for (int i = 0; i < 4; ++i)
      {
	 currentlySelectedObjects[i]->setText("No item selected!");
	 currentlySelectedObjectPrices[i]->setText("$0");
      }
   }
}

void ConfirmationWindow::confirmPurchase()
{
   int optionSelected;
   QMessageBox msgBox;
   
   msgBox.setText("Confirm Purchase of Parts");
   msgBox.setInformativeText("This will place your order to FakeCompany. Are you sure?");
   msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
   msgBox.setDefaultButton(QMessageBox::Cancel);
   optionSelected = msgBox.exec();
   
   if (optionSelected == QMessageBox::Ok)
      emit sendReset();
}
