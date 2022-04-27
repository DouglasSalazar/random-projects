/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controle;
import entidades.Pidion;
import interfaces.JanelaCadastroPidion;
/**
 *
 * @author Douglas
 */
public class ControladorCadastroPidion {
    public ControladorCadastroPidion(){
        new JanelaCadastroPidion(this).setVisible(true);
    }
    
    public String inserirPidion(Pidion pidion){
        Pidion pidion1 = Pidion.buscaPidion(String.valueOf(pidion.getNum_Bunge()));
        if(pidion1 == null){
            return Pidion.inserirPidion(pidion);
        }else{
            return "Pidion já cadastrado";
        }
    }
    
    public String alterarPidion(Pidion pidion){
        Pidion pidion1 = Pidion.buscaPidion(String.valueOf(pidion.getNum_Bunge()));
        if(pidion1 != null){
            return Pidion.alterarPidion(pidion);
        }else{
            return "Pidion não cadastrado";
        }
    }

    public String removerPidion(Pidion pidion){
        Pidion usuario1 = Pidion.buscaPidion(String.valueOf(pidion.getNum_Bunge()));
        if(usuario1 != null){
            return Pidion.removerPidion(pidion);
        }else{
            return "Pidion não cadastrado";
        }
    }

}
