#ifndef MOTHERBOARDWINDOW_H
#define MOTHERBOARDWINDOW_H

#include "PartPageInterface.h"

class MotherboardWindow : public PartPageInterface
{
   public:
      // Constructor
      MotherboardWindow();
      
      // Destructor
      ~MotherboardWindow();
   
   protected:
      // Instantiated virtual function to initialize our vector values
      virtual void initVectorValues();
      
      // Instantiated virtual function to update info for spec windows
      virtual void loadSpecs();
      
      // Instantiated virtual function to load our iamges
      virtual void loadAssets();
};
#endif
