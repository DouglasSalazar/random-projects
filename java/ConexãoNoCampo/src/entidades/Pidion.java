
package entidades;
import entidades.Visão;
import java.sql.ResultSet; 
import java.sql.SQLException; 
import java.util.Vector; 
import persistência.BD;
import java.sql.PreparedStatement;

public class Pidion {
    private int ID;
    private int num_Patrimônio;
    private int num_Bunge;
    private int num_Patrimônio_Impressora;
    private String modelo;
    private String sérieImpressora;
    
    public Pidion(int ID, int num_Patrimônio, int num_Bunge, int num_Patrimônio_Impressora, String modelo, String sérieImpressora){
        this.ID = ID;
        this.num_Patrimônio = num_Patrimônio;
        this.num_Bunge = num_Bunge;
        this.num_Patrimônio_Impressora = num_Patrimônio_Impressora;
        this.modelo = modelo;
        this.sérieImpressora = sérieImpressora;
    }
    
    public int getID(){
        return this.ID;
    }
    
    public void setID(int ID){
        this.ID = ID;
    }
    
    public int getNum_Patrimônio(){
        return this.num_Patrimônio;
    }
    
    public void setNum_Patrimônio(int num_Patrimônio){
        this.num_Patrimônio = num_Patrimônio;
    }
    
    public int getNum_Bunge(){
       return this.num_Bunge;
    }
    
    public void setNum_Bunge(int num_Bunge){
        this.num_Bunge = num_Bunge;
    }
    
    public int getNum_Patrimônio_Impressora(){
        return this.num_Patrimônio_Impressora;
    }
    
    public void setNum_Patrimônio_Impressora(int num_Patrimônio_Impressora){
        this.num_Patrimônio_Impressora = num_Patrimônio_Impressora;
    }
    
    public String getModelo(){
        return this.modelo;
    }
    
    public void setModelo(String modelo){
        this.modelo = modelo;
    }
    
    public String getSérieImpressora(){
        return this.sérieImpressora;
    }
    
    public void setSérieImpressora(String sérieImpressora){
        this.sérieImpressora = sérieImpressora;
    }
    
    public Visão<String> getVisão () {        
        return new Visão<String>(String.valueOf(ID),String.valueOf(num_Bunge)+"-"+modelo);    
    }
    
    
    public static Pidion buscaPidionID(String id){
        String sql = "SELECT * FROM pidion WHERE ID = ?";
        ResultSet lista_resultados = null;
        Pidion aux = null;
                 
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql); 
            comando.setString(1, id);
            lista_resultados = comando.executeQuery();            
            while (lista_resultados.next()) {                
                aux = (new Pidion(Integer.valueOf(lista_resultados.getString("ID")),Integer.valueOf(lista_resultados.getString("num_Patrimônio")),Integer.valueOf(lista_resultados.getString("num_Bunge")),Integer.valueOf(lista_resultados.getString("num_Patrimônio_Impressora")),lista_resultados.getString("modelo"),lista_resultados.getString("sérieImpressora")));
            }
            lista_resultados.close();            
            comando.close();        
        } catch (SQLException exceção_sql) {exceção_sql.printStackTrace ();}     
        return aux;
    }
    
    public static Vector<Pidion> getPidion(){
        String sql = "SELECT * FROM pidion";
        ResultSet lista_resultados = null;
        Vector <Pidion> seleção_pidion = new Vector <Pidion>();
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);            
            lista_resultados = comando.executeQuery();            
            while (lista_resultados.next()) {                
                seleção_pidion.add(new Pidion(Integer.valueOf(lista_resultados.getString("ID")),Integer.valueOf(lista_resultados.getString("num_Patrimônio")),Integer.valueOf(lista_resultados.getString("num_Bunge")),Integer.valueOf(lista_resultados.getString("num_Patrimônio_Impressora")),lista_resultados.getString("modelo"),lista_resultados.getString("sérieImpressora")));
            }
            lista_resultados.close();            
            comando.close();        
        } catch (SQLException exceção_sql) {exceção_sql.printStackTrace ();}     
        return seleção_pidion;
     }
    
    public static String inserirPidion(Pidion pidion){
        String sql = "INSERT INTO pidion (num_Patrimônio,num_Bunge,num_Patrimônio_Impressora,modelo,sérieImpressora) " + "VALUES (?, ?, ?, ?, ?)";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, String.valueOf(pidion.getNum_Patrimônio()));
            comando.setString(2, String.valueOf(pidion.getNum_Bunge()));
            comando.setString(3, String.valueOf(pidion.getNum_Patrimônio_Impressora()));
            comando.setString(4, pidion.getModelo());
            comando.setString(5, pidion.getSérieImpressora());
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na Inserção do Pidion no Banco!";
        }
    }
    
    public static String alterarPidion(Pidion pidion){
        String sql = "UPDATE pidion SET num_Patrimônio = ?,num_Patrimônio_Impressora = ?, modelo = ?,sérieImpressora = ? " + "WHERE num_Bunge = ?";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, String.valueOf(pidion.getNum_Patrimônio()));
            comando.setString(2, String.valueOf(pidion.getNum_Patrimônio_Impressora()));
            comando.setString(3, pidion.getModelo());
            comando.setString(4, pidion.getSérieImpressora());
            comando.setString(5, String.valueOf(pidion.getNum_Bunge()));
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na Alteração do Pidion no Banco!";
        }
    }
    
    public static String removerPidion(Pidion pidion){
        String sql = "DELETE FROM pidion " + "WHERE num_Bunge = ?";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, String.valueOf(pidion.getNum_Bunge()));
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na Remoção do Pidion do Banco!";
        }
    }

    
    public static Pidion buscaPidion(String n_bunge){
        String sql = "SELECT * FROM pidion"+" WHERE num_Bunge = ?";
        ResultSet list_resultados = null;
        Pidion pidion = null;
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1,n_bunge);
            list_resultados = comando.executeQuery();
            while(list_resultados.next()){

                pidion = new Pidion(list_resultados.getInt("ID"),
                        Integer.valueOf(list_resultados.getString("num_Patrimônio")),
                        Integer.valueOf(n_bunge),
                        Integer.valueOf(list_resultados.getString("num_Patrimônio_Impressora")),
                        list_resultados.getString("modelo"),
                        list_resultados.getString("sérieImpressora")
                    );
            }
            
        }catch(SQLException exceção_sql){
            exceção_sql.printStackTrace();
            pidion = null;
        }
        return pidion;
    }
    public static Vector <Visão<String>> getVisões () {        
         String sql = "SELECT ID, num_Bunge,modelo FROM pidion ORDER BY num_Bunge";        
         ResultSet lista_resultados = null;        
         Vector<Visão<String>> visões = new Vector();        
         String id;        
         try {            
             PreparedStatement comando = BD.conexão.prepareStatement(sql);            
             lista_resultados = comando.executeQuery();            
             while (lista_resultados.next()) {                
                 id = lista_resultados.getString("ID");                
                 visões.addElement(new Visão<String> (id,                     
                         lista_resultados.getString("num_Bunge")+"-"+lista_resultados.getString("modelo")));            
            }                         
            lista_resultados.close();            
            comando.close();        
         } catch (SQLException exceção_sql) {exceção_sql.printStackTrace ();}        
         return visões;    
     }
     @Override    
     public String toString () {        
         return String.valueOf(num_Bunge);    
     }

}
