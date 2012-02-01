/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * sortGUI.java
 *
 * Created on Feb 1, 2012, 1:18:21 AM
 */

package sortaseapp;

import java.text.DecimalFormat;

/**
 *
 * @author ouroboros
 */
public class sortGUI extends javax.swing.JFrame {

    /** Creates new form sortGUI */
    public sortGUI() {
        initComponents();
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        calcRxn = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        nucConcLabel = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        rxnResultsBox = new javax.swing.JTextArea();
        nucConcInput = new javax.swing.JTextField();
        subStockConcInput = new javax.swing.JTextField();
        sortStockConcInput = new javax.swing.JTextField();
        srtRxnConcInput = new javax.swing.JTextField();
        ratioInput = new javax.swing.JTextField();
        sortStockConcLabel = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        totalRxnVolInput = new javax.swing.JTextField();
        sampleDataButton = new javax.swing.JButton();

        jButton1.setText("jButton1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        calcRxn.setText("calcRxn");
        calcRxn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                calcRxnActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("DejaVu Sans", 0, 18)); // NOI18N
        jLabel1.setText("Enter Reaction Parameters");

        nucConcLabel.setText("Nucleophile Concentration");

        rxnResultsBox.setColumns(20);
        rxnResultsBox.setRows(5);
        jScrollPane1.setViewportView(rxnResultsBox);

        sortStockConcLabel.setText("Substrate Stock Concentration");

        jLabel4.setText("Sortase Stock Concentration");

        jLabel5.setText("Sortase Reaction Concentration");

        jLabel6.setText("Ratio of Nucleophile:Substrate");

        jLabel7.setText("Reaction Results (in uM or uL:");

        jLabel8.setText("Total Reaction Volume Desired");

        sampleDataButton.setText("Fill Sample Data");
        sampleDataButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sampleDataButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addContainerGap()
                                        .addComponent(nucConcLabel))
                                    .addGroup(layout.createSequentialGroup()
                                        .addContainerGap()
                                        .addComponent(sortStockConcLabel))
                                    .addGroup(layout.createSequentialGroup()
                                        .addContainerGap()
                                        .addComponent(jLabel4))
                                    .addGroup(layout.createSequentialGroup()
                                        .addContainerGap()
                                        .addComponent(jLabel6))
                                    .addGroup(layout.createSequentialGroup()
                                        .addContainerGap()
                                        .addComponent(jLabel5)))
                                .addGap(46, 46, 46)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(subStockConcInput, javax.swing.GroupLayout.DEFAULT_SIZE, 70, Short.MAX_VALUE)
                                    .addComponent(sortStockConcInput, javax.swing.GroupLayout.DEFAULT_SIZE, 70, Short.MAX_VALUE)
                                    .addComponent(srtRxnConcInput, javax.swing.GroupLayout.DEFAULT_SIZE, 70, Short.MAX_VALUE)
                                    .addComponent(ratioInput, javax.swing.GroupLayout.DEFAULT_SIZE, 70, Short.MAX_VALUE)
                                    .addComponent(nucConcInput, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.PREFERRED_SIZE, 70, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(jLabel8)
                                .addGap(53, 53, 53)
                                .addComponent(totalRxnVolInput, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)))
                        .addGap(18, 18, 18)
                        .addComponent(calcRxn))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(54, 54, 54)
                        .addComponent(jLabel1)))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel7)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(sampleDataButton))
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 318, Short.MAX_VALUE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(32, 32, 32)
                .addComponent(jLabel1)
                .addGap(29, 29, 29)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(nucConcLabel)
                    .addComponent(nucConcInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(6, 6, 6)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(sortStockConcLabel)
                    .addComponent(subStockConcInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(sortStockConcInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(srtRxnConcInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(ratioInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(totalRxnVolInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8))
                .addContainerGap())
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(164, Short.MAX_VALUE)
                .addComponent(calcRxn)
                .addGap(107, 107, 107))
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(sampleDataButton)
                    .addComponent(jLabel7))
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 229, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void calcRxnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_calcRxnActionPerformed

        doCalcs();
        // TODO add your handling code here:
    }//GEN-LAST:event_calcRxnActionPerformed

    private void sampleDataButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sampleDataButtonActionPerformed

        //The string we will concat to until we are ready to output
        //String outputFormat = "";

        //set up some out of the box variables
        nucConcInput.setText("200");
        subStockConcInput.setText("150");
        srtRxnConcInput.setText("5");
        sortStockConcInput.setText("300");
        ratioInput.setText("2");
        totalRxnVolInput.setText("9500");

        doCalcs();
        //create the calculator object
        //sortCalc maincalc = new sortCalc();

    }//GEN-LAST:event_sampleDataButtonActionPerformed

    public void doCalcs(){
        //The string we will concat to until we are ready to output
        String outputFormat = "";
        //create the calculator object
        sortCalc maincalc = new sortCalc();

        //pass from input fields to the variables of object
        maincalc.setNucStockConc(Double.valueOf(nucConcInput.getText()));
        maincalc.setSubStockConc(Double.valueOf(subStockConcInput.getText()));
        maincalc.setSortaseStockConc(Double.valueOf(sortStockConcInput.getText()));
        maincalc.setSortaseRxnConc(Double.valueOf(srtRxnConcInput.getText()));
        maincalc.setRatio(Double.valueOf(ratioInput.getText()));
        maincalc.setVolumeRxn(Double.valueOf(totalRxnVolInput.getText()));

        //handle the result object... use and object typecaster object = (objectclassname) getvaluefromfunction();
        rxnResult myres = new rxnResult();
        myres = (rxnResult) maincalc.calcForTotalVol();

        //make an object to format decimals:
        DecimalFormat decform = new DecimalFormat("#####.##");

        //output our results to text box from result object...
        outputFormat += "Nucleophile Concentration: " + String.valueOf(decform.format(myres.getNucFinalConc())) + "\n";
        outputFormat += "Nucleophile Volume: " + String.valueOf(decform.format(myres.getNucFinalVol())) + "\n";
        outputFormat += "Substrate Concentration: " + String.valueOf(decform.format(myres.getSubFinalConc())) + "\n";
        outputFormat += "Substrate Volume: " + String.valueOf(decform.format(myres.getSubFinalVol())) + "\n";
        outputFormat += "Sortase Stock Volume Required: " + String.valueOf(decform.format(myres.getVolSortase())) + "\n";

        rxnResultsBox.setText(outputFormat);
    }



    /**
    * @param args the command line arguments
    */
    public void mainDisplay() {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new sortGUI().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton calcRxn;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextField nucConcInput;
    private javax.swing.JLabel nucConcLabel;
    private javax.swing.JTextField ratioInput;
    private javax.swing.JTextArea rxnResultsBox;
    private javax.swing.JButton sampleDataButton;
    private javax.swing.JTextField sortStockConcInput;
    private javax.swing.JLabel sortStockConcLabel;
    private javax.swing.JTextField srtRxnConcInput;
    private javax.swing.JTextField subStockConcInput;
    private javax.swing.JTextField totalRxnVolInput;
    // End of variables declaration//GEN-END:variables

}