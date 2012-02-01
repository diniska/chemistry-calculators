/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sortaseapp;

/**
 *
 * @author ouroboros
 */
public class sortCalc {

    private double sortaseStockConc;
    private double sortaseRxnConc;
    private double nucStockConc;
    private double subStockConc;
    private double ratio;
    private double volumeRxn;

    //this is the logic for the from total volume calculator
    public Object calcForTotalVol(){

        rxnResult myresult = new rxnResult();

        /* main formula:
         *
    sort_volume = (total_volume * sortase_final) / sortase_stock
    volleft = (total_volume) - (sort_volume)
    n_conc_final = (volleft / total_volume) / ((ratio / acb_stock) + (1 / n_stock))
    acb_conc_final = (n_conc_final * ratio)
    acb_volume = (acb_conc_final * total_volume ) / (acb_stock)
    n_volume = (n_conc_final * total_volume) / (n_stock)

         */

        myresult.setVolSortase((volumeRxn * sortaseRxnConc) / sortaseStockConc);
        double volleft = volumeRxn - myresult.getVolSortase();
        myresult.setSubFinalConc((volleft / volumeRxn) / ((ratio / nucStockConc) + (1 / subStockConc)));
        myresult.setNucFinalConc(myresult.getSubFinalConc() * ratio);
        myresult.setNucFinalVol((myresult.getNucFinalConc() * volumeRxn ) / nucStockConc);
        myresult.setSubFinalVol((myresult.getSubFinalConc() * volumeRxn) / nucStockConc);

        //pop out the object holding a lot of variables
        return myresult;
    }


    public double getSortaseRxnConc() {
        return sortaseRxnConc;
    }

    public void setSortaseRxnConc(double sortaseRxnConc) {
        this.sortaseRxnConc = sortaseRxnConc;
    }

    public double getNucStockConc() {
        return nucStockConc;
    }

    public void setNucStockConc(double nucStockConc) {
        this.nucStockConc = nucStockConc;
    }

    public double getRatio() {
        return ratio;
    }

    public void setRatio(double ratio) {
        this.ratio = ratio;
    }

    public double getSortaseStockConc() {
        return sortaseStockConc;
    }

    public void setSortaseStockConc(double sortaseStockConc) {
        this.sortaseStockConc = sortaseStockConc;
    }

    public double getSubStockConc() {
        return subStockConc;
    }

    public void setSubStockConc(double subStockConc) {
        this.subStockConc = subStockConc;
    }

    public double getVolumeRxn() {
        return volumeRxn;
    }

    public void setVolumeRxn(double volumeRxn) {
        this.volumeRxn = volumeRxn;
    }



}
