
package entidades;

public class Data {
    private String dia;
    private String mês;
    private String ano;
    
    public Data(String dia, String mês, String ano){
        this.dia = dia;
        this.mês = mês;
        this.ano = ano;        
    }
    
    public String getDia(){
        return this.dia;
    }
    
    public void setDia (String dia){
        this.dia = dia;
    }
    
    public String getMês(){
        return mês;
    }
    
    public void setMês(String mês){
        this.mês = mês;
    }
    
    public String getAno(){
        return this.ano;
    }
    
    public void setAno(String ano){
        this.ano = ano;
    }

    public String toString(){
        return this.dia + "/" + this.mês +"/"+this.ano;
    }
}
