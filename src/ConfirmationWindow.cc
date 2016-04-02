#include <QtGui>
#include "ConfirmationWindow.h"

ConfirmationWindow::ConfirmationWindow()
{
   // Variable declarations
   QHBoxLayout* mainLayout = new QHBoxLayout();
   QVBoxLayout* leftLayout = new QVBoxLayout();
   QVBoxLayout* rightLayout = new QVBoxLayout();
   
   // Variable instantiations
   budgetAmount = 0;
   currentAmount = 0;
   
   // Ensure empty vectors
   currentlySelectedObjects.clear();
   currentlySelectedObjectPrices.clear();
   
   for (int i = 0; i < 4; ++i)
   {
      currentlySelectedObjects.push_back(new QLabel("No item selected!"));
      currentlySelectedObjectPrices.push_back(new QLabel("$0"));
      leftLayout->addWidget(currentlySelectedObjects[i]);
      rightLayout->addWidget(currentlySelectedObjectPrices[i]);
   }
   
   currentlySelectedObjects.push_back(new QLabel("Current Budget Amount"));
   currentlySelectedObjects.push_back(new QLabel("Cost"));
   currentlySelectedObjectPrices.push_back(new QLabel("$" + QString::number(budgetAmount)));
   currentlySelectedObjectPrices.push_back(new QLabel("$" + QString::number(currentAmount)));
   leftLayout->addWidget(currentlySelectedObjects[4]);
   rightLayout->addWidget(currentlySelectedObjectPrices[4]);
   leftLayout->addWidget(currentlySelectedObjects[5]);
   rightLayout->addWidget(currentlySelectedObjectPrices[5]);
   
   mainLayout->addLayout(leftLayout);
   mainLayout->addLayout(rightLayout);
   this->setLayout(mainLayout);
}

ConfirmationWindow::~ConfirmationWindow()
{
}

void ConfirmationWindow::updateBudgetAmount(double givenBudget)
{
   budgetAmount = givenBudget;
   currentlySelectedObjectPrices[4]->setText("$" + QString::number(budgetAmount));
}

void ConfirmationWindow::updateCurrentAmount(double givenAmount)
{
   currentAmount = givenAmount;
   currentlySelectedObjectPrices[5]->setText("$" + QString::number(currentAmount));
}

void ConfirmationWindow::updateVectors(QString newName, double newAmount, int indexNumber)
{
   if (indexNumber >= 0)
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
   emit sendReset();
}

void ConfirmationWindow::resetSelection()
{
   //for (int i = 4; i < 4; ++i)
   //{
      //currentlySelectedObjects->setText("No item selected!");
      //currentlySelectedObjectPrices->setText("$0");
   //}
}
