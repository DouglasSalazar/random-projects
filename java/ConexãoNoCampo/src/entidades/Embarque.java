
package entidades;
import java.sql.ResultSet; 
import java.sql.SQLException; 
import java.util.Vector; 
import persistência.BD;
import java.sql.PreparedStatement;
import entidades.Data;



public class Embarque {
    public enum Situação{Embarcando, Suspenso};
    private int ID;
    private Data data;
    private int OS;
    private String local_Embarque;
    private String cidade;
    private int pidion;
    private float volume_Embarque;
    private Situação situação;
    private String usuário;
    
    public Embarque(int ID, Data data, int OS, String local_Embarque, String cidade, int pidion, float volume_Embarque, Situação situação, String usuário){
        this.ID = ID;
        this.data = data;
        this.OS = OS;
        this.local_Embarque = local_Embarque;
        this.cidade = cidade;
        this.pidion = pidion;
        this.volume_Embarque = volume_Embarque;
        this.situação = situação;
        this.usuário = usuário;
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
    
    public int getPidion(){
        return this.pidion;
    } 
    
    public void setPidion(int pidion){
        this.pidion = pidion;
    }
    
    public float getVolume_Embarque(){
        return this.volume_Embarque;
    } 
    
    public void setVolume_Embarque(float volume_Embarque){
        this.volume_Embarque = volume_Embarque;
    }
    
    public Situação getSituação(){
        return this.situação;
    }
    
    public void setSituação(Situação situação){
        this.situação = situação;
    }
    
    public String getUsuário(){
        return this.usuário;
    }
    
    public void setUsuário(String usuário){
        this.usuário = usuário;
    }
    
    public static String alterarEmbarque(Embarque embarque){
        String sql = "UPDATE embarque SET data_Embatque = ?,OS = ?,local_Embarque = ?,cidade = ?,pidionID = ?,volume_Embarque = ?,situação = ?, usuárioID = ? " + "WHERE id = ?";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, embarque.getData().getAno()+"-"+embarque.getData().getMês()+"-"+embarque.getData().getDia());
            comando.setString(2, String.valueOf(embarque.getOS()));
            comando.setString(3, embarque.getLocal_Embarque());
            comando.setString(4, embarque.getCidade());
            comando.setString(5, String.valueOf(embarque.getPidion()));
            comando.setString(6, String.valueOf(embarque.getVolume_Embarque()));
            comando.setString(7, String.valueOf(embarque.getSituação()));
            comando.setString(8, String.valueOf(embarque.getUsuário()));
            comando.setString(9, String.valueOf(embarque.getID())); 
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na Inserção do Embarque no Banco!";
        }

    }
    public static String removerEmbarque(Embarque embarque){
        String sql = "DELETE FROM embarque " + "WHERE id = ?";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, String.valueOf(embarque.getID()));
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na Remoção do Embarque do Banco!";
        }
    }

    
    public static String inserirEmbarque(Embarque embarque){
        String sql = "INSERT INTO embarque (data_Embatque,OS,local_Embarque,cidade,pidionID,volume_Embarque,situação,usuárioID) " + "VALUES (?, ?, ?, ?, ?, ?, ?,?)";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, embarque.getData().getAno()+"-"+embarque.getData().getMês()+"-"+embarque.getData().getDia());
            comando.setString(2, String.valueOf(embarque.getOS()));
            comando.setString(3, embarque.getLocal_Embarque());
            comando.setString(4, embarque.getCidade());
            comando.setString(5, String.valueOf(embarque.getPidion()));
            comando.setString(6, String.valueOf(embarque.getVolume_Embarque()));
            comando.setString(7, String.valueOf(embarque.getSituação()));
            comando.setString(8, String.valueOf(embarque.getUsuário()));
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na Inserção do Embarque no Banco!";
        }
    }
    
    public static Embarque buscaEmbarque(String codigo){
        String sql = "SELECT * FROM embarque"+" WHERE id = ?";
        ResultSet list_resultados = null;
        Embarque embarque = null;
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1,codigo);
            list_resultados = comando.executeQuery();
            while(list_resultados.next()){
                
                String[] splitted = list_resultados.getString("data_Embatque").split("-");
                Data data_Embarque = new Data(splitted[2],splitted[1],splitted[0]);
                Situação aux = null;
                if(list_resultados.getString("situação").equals("Embarcando")){
                    aux = Situação.Embarcando;
                }else{
                    aux = Situação.Suspenso;
                }
                embarque = new Embarque(list_resultados.getInt("ID"),
                        data_Embarque,
                        Integer.valueOf(list_resultados.getString("OS")),
                        list_resultados.getString("local_Embarque"),
                        list_resultados.getString("cidade"),
                        Integer.valueOf(list_resultados.getString("pidionID")),
                        Float.valueOf(list_resultados.getString("volume_Embarque")),
                        aux,
                        list_resultados.getString("usuárioID")
                    );
            }
            
        }catch(SQLException exceção_sql){
            exceção_sql.printStackTrace();
            embarque = null;
        }
        return embarque;
    }
    
    public static Vector <Embarque> buscaEmbarqueList(){
        String sql = "SELECT * FROM embarque";
        ResultSet list_resultados = null;
        Vector <Embarque> embarque = new Vector();

        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            list_resultados = comando.executeQuery();
            while(list_resultados.next()){
                String[] splitted = list_resultados.getString("data_Embatque").split("-");
                Data data_Embarque = new Data(splitted[2],splitted[1],splitted[0]);
                Situação aux;
                if(list_resultados.getString("situação").equals("Embarcando")){
                    aux = Situação.Embarcando;
                }else{
                    aux = Situação.Suspenso;
                }
                embarque.add(new Embarque(list_resultados.getInt("ID"),
                        data_Embarque,
                        Integer.valueOf(list_resultados.getString("OS")),
                        list_resultados.getString("local_Embarque"),
                        list_resultados.getString("cidade"),
                        Integer.valueOf(list_resultados.getString("pidionID")),
                        Float.valueOf(list_resultados.getString("volume_Embarque")),
                        aux,
                        list_resultados.getString("usuárioID")
                    ));
            }
        
        }catch(SQLException exceção_sql){
            exceção_sql.printStackTrace();
            embarque = null;
        }
        return embarque;
    }
    public static Vector <Embarque> buscaEmbarqueFiltro(Embarque embarque1, Data data_até){
        Vector <Embarque> embarque = new Vector();
        ResultSet list_resultados = null;
        String sql = "SELECT * FROM embarque WHERE";
        
        if (embarque1.getData()!=null) sql = sql + " data_Embatque >=  " + embarque1.getData().getAno()+embarque1.getData().getMês()+embarque1.getData().getDia();
        if (data_até!=null) sql = sql + " AND data_Embatque <=  " + data_até.getAno()+data_até.getMês()+data_até.getDia();
        if (embarque1.getOS()!=-1) sql = sql + " AND OS = " +String.valueOf(embarque1.getOS());
        if (embarque1.getLocal_Embarque()!= null) sql = sql +" AND local_Embarque = '" + embarque1.getLocal_Embarque()+"'";
        if (embarque1.getCidade()!= null) sql = sql+" AND cidade = '" + embarque1.getCidade()+"'";
        if (embarque1.getPidion()!=-1) sql = sql+" AND pidionID = " + String.valueOf(embarque1.getPidion());
        if (embarque1.getVolume_Embarque() != -1) sql = sql + " AND volume_Embarque = " +String.valueOf(embarque1.getVolume_Embarque());
        if (embarque1.getSituação()!=null) sql = sql + " AND situação = '" + String.valueOf(embarque1.getSituação()+"'") ;
        if (!embarque1.getUsuário().equals("-1")) sql = sql + " AND usuárioID = "+String.valueOf(embarque1.getUsuário());
     
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            list_resultados = comando.executeQuery();
            while(list_resultados.next()){
                String[] splitted = list_resultados.getString("data_Embatque").split("-");
                Data data_Embarque = new Data(splitted[2],splitted[1],splitted[0]);
                Situação aux;
                if(list_resultados.getString("situação").equals("Embarcando")){
                    aux = Situação.Embarcando;
                }else{
                    aux = Situação.Suspenso;
                }
                embarque.add(new Embarque(list_resultados.getInt("ID"),
                        data_Embarque,
                        Integer.valueOf(list_resultados.getString("OS")),
                        list_resultados.getString("local_Embarque"),
                        list_resultados.getString("cidade"),
                        Integer.valueOf(list_resultados.getString("pidionID")),
                        Float.valueOf(list_resultados.getString("volume_Embarque")),
                        aux,
                        list_resultados.getString("usuárioID")
                    ));
            }
            comando.close();
            
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
        }        
        return embarque;
    }
    
    
    public String toString(){
        String sql = "SELECT u.ID, u.Nome,p.ID, p.num_Bunge FROM usuário u, pidion p WHERE u.ID = ? AND p.ID = ?";
        ResultSet list_resultados = null;
        String nome=null;
        String pidion=null;
        
         
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, String.valueOf(this.getUsuário()));
            comando.setString(2, String.valueOf(this.getPidion()));
            list_resultados = comando.executeQuery();
            while(list_resultados.next()){
                nome=list_resultados.getString("Nome");
                pidion=list_resultados.getString("num_Bunge");
            }
        comando.close();
        }catch(SQLException exceção_sql){
            exceção_sql.printStackTrace();
           
        }
        return "ID: " + this.ID + "\nOS: " + this.OS + "\nData: " + this.data.toString() + "\nLocal de Embarque: " + this.local_Embarque + "\nCidade: " + this.cidade + "\nPidion: " + pidion + "\nVolume do Embarque: " + this.volume_Embarque +"\nNome do Usuário: "+ nome +"\nSituação: " + this.situação;
    }
}
