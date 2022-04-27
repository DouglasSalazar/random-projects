
package entidades;
import java.sql.ResultSet; 
import java.sql.SQLException; 
import java.util.Vector; 
import persistência.BD;
import java.sql.PreparedStatement;




public class EmbarquePesquisa {
    private int ID;
    private Data data;
    private int OS;
    private String local_Embarque;
    private String cidade;
    private String pidion;
    private float volume_Embarque;
    private String situação;
    private String usuário;
    private String profissão;
    private String impressora;
    public EmbarquePesquisa(int ID, Data data, int OS, String local_Embarque, String cidade, String pidion, float volume_Embarque, String situação, String usuário, String profissão, String impressora){
        this.ID = ID;
        this.data = data;
        this.OS = OS;
        this.local_Embarque = local_Embarque;
        this.cidade = cidade;
        this.pidion = pidion;
        this.volume_Embarque = volume_Embarque;
        this.situação = situação;
        this.usuário = usuário;
        this.profissão = profissão;
        this.impressora = impressora;
    }
    
    public int getID(){
        return this.ID;
    }
    
    public void setID(int ID){
        this.ID = ID;
    }
    
    public Data getData(){
        return this.data;
    }
    
    public void setData(Data data){
        this.data = data;
    }
    
    public int getOS(){
        return this.OS;
    }
    
    public void setOS(int OS){
        this.OS = OS;
    }
    
    public String getLocal_Embarque(){
        return this.local_Embarque;
    }
    
    public void setLocal_Embarque(String local_Embarque){
        this.local_Embarque = local_Embarque;
    }
    
    public String getCidade(){
        return this.cidade;
    }
    
    public void setCidade(String cidade){
        this.cidade = cidade;
    }
    
    public String getPidion(){
        return this.pidion;
    } 
    
    public void setPidion(String pidion){
        this.pidion = pidion;
    }
    
    public float getVolume_Embarque(){
        return this.volume_Embarque;
    } 
    
    public void setVolume_Embarque(float volume_Embarque){
        this.volume_Embarque = volume_Embarque;
    }
    
    public String getSituação(){
        return this.situação;
    }
    
    public void setSituação(String situação){
        this.situação = situação;
    }
    
    public String getUsuário(){
        return this.usuário;
    }
    
    public void setUsuário(String usuário){
        this.usuário = usuário;
    }
    
    public String getProfissão(){
        return this.profissão;
    }
    
    public void setProfissão(String profissão){
        this.profissão = profissão;
    }
    
    public String getImpressora(){
        return this.impressora;
    }
    
    public void setImpressora(String impressora){
        this.impressora = impressora;
    }
    
    public static Vector <EmbarquePesquisa> buscaEmbarqueFiltro(EmbarquePesquisa embarque1, Data data_até){
        Vector <EmbarquePesquisa> embarque = new Vector();
        ResultSet list_resultado = null;
        String sql = "SELECT e.ID, e.data_Embatque,e.OS,e.local_Embarque,e.cidade,e.volume_Embarque,e.situação, p.num_Bunge, p.modelo, u.Nome, u.Profissão FROM embarque e, pidion p, usuário u WHERE e.usuárioID = u.ID AND e.pidionID = p.ID ";
        
        if (embarque1.getData()!=null) sql = sql + "AND DATE(e.data_Embatque) >=  '" + embarque1.getData().getAno()+"-"+embarque1.getData().getMês()+"-"+embarque1.getData().getDia()+"'";
        if (data_até!=null) sql = sql + " AND DATE(e.data_Embatque) <=  '" + data_até.getAno()+"-"+data_até.getMês()+"-"+data_até.getDia()+"'";
        if (embarque1.getOS()!=-1) sql = sql + " AND e.OS = " +String.valueOf(embarque1.getOS());
        if (embarque1.getLocal_Embarque()!= null) sql = sql +" AND e.local_Embarque = '" + embarque1.getLocal_Embarque()+"'";
        if (embarque1.getCidade()!= null) sql = sql+" AND e.cidade = '" + embarque1.getCidade()+"'";
        if (embarque1.getPidion()!= null) sql = sql + " AND p.num_Bunge = " + embarque1.getPidion();
        if (embarque1.getVolume_Embarque() != -1) sql = sql + " AND e.volume_Embarque = " +String.valueOf(embarque1.getVolume_Embarque());
        if (embarque1.getSituação()!=null) sql = sql + " AND e.situação =  '" + embarque1.getSituação()+"'";
        if (!embarque1.getUsuário().equals("-1")) sql = sql + " AND u.ID = "+String.valueOf(embarque1.getUsuário());
        if (embarque1.getImpressora()!=null) sql = sql + " AND p.modelo = '"+embarque1.getImpressora()+"'";
        if (embarque1.getProfissão()!=null) sql = sql + " AND u.Profissão = '"+embarque1.getProfissão()+"'";
        
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);            
            list_resultado = comando.executeQuery(); 
            while (list_resultado.next()){
                String[] splitted = list_resultado.getString("data_Embatque").split("-");
                Data data_Embarque = new Data(splitted[2],splitted[1],splitted[0]);
                embarque.add(new EmbarquePesquisa(list_resultado.getInt("ID"),
                        data_Embarque,
                        Integer.valueOf(list_resultado.getString("OS")),
                        list_resultado.getString("local_Embarque"),
                        list_resultado.getString("cidade"),
                        list_resultado.getString("num_Bunge"),
                        Float.valueOf(list_resultado.getString("volume_Embarque")),
                        list_resultado.getString("situação"),
                        list_resultado.getString("Nome"),
                        list_resultado.getString("profissão"),
                        list_resultado.getString("modelo")
                    ));
            }
            
            list_resultado.close();            
            comando.close();   
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
        }        
        return embarque;
    }
    
    
    public String toString(){        
        return "ID: " + this.ID + "\nOS: " + this.OS + "\nData: " + this.data.toString() + "\nLocal de Embarque: " + this.local_Embarque + "\nCidade: " + this.cidade + "\nPidion: " + this.pidion + "\nImpressora: " + this.impressora + "\nVolume do Embarque: " + this.volume_Embarque +"\nNome do Usuário: "+ this.usuário + "\nProfissão: "+ this.profissão +"\nSituação: " + this.situação;
    }
}
