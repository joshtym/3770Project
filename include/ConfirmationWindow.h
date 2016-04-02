#ifndef CONFIRMATIONWINDOW_H
#define CONFIRMATIONWINDOW_H

#include <QWidget>
#include <vector>

// Forward Declarations
class QString;
class QLabel;

class ConfirmationWindow : public QWidget
{
   // Meta object compiler
   Q_OBJECT
   
   public:
      // Default constructor
      ConfirmationWindow();
      
      // Destructor of class
      ~ConfirmationWindow();
      
      // Public function to update costs and our vectors
      void updateBudgetAmount(double);
      void updateCurrentAmount(double);
      void updateVectors(QString, double, int);
      
   signals:
      void sendReset();
      
   private slots:
      void confirmPurchase();
      
   private:
      std::vector<QLabel*> currentlySelectedObjects;
      std::vector<QLabel*> currentlySelectedObjectPrices;
      double currentAmount;
      double budgetAmount;
};
#endif
