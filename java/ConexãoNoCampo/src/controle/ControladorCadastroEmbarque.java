/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controle;
import entidades.Embarque;
import interfaces.JanelaCadastroEmbarque;
/**
 *
 * @author Douglas
 */
public class ControladorCadastroEmbarque {
    public ControladorCadastroEmbarque(){
        new JanelaCadastroEmbarque(this).setVisible(true);
    }
    
    public String inserirEmbarque(Embarque embarque){
        Embarque embarque1 = Embarque.buscaEmbarque(String.valueOf(embarque.getID()));
        if(embarque1 == null){
            return Embarque.inserirEmbarque(embarque);
        }else{
            return "Embarque já cadastrado";
        }
    }
    
    public String alterarEmbarque(Embarque embarque){
        Embarque embarque1 = Embarque.buscaEmbarque(String.valueOf(embarque.getID()));
        if(embarque1 != null){
            return Embarque.alterarEmbarque(embarque);
        }else{
            return "Embarque não cadastrado";
        }
    }

    public String removerEmbarque(Embarque embarque){
        Embarque embarque1 = Embarque.buscaEmbarque(String.valueOf(embarque.getID()));
        if(embarque1 != null){
            return Embarque.removerEmbarque(embarque);
        }else{
            return "Embarque não cadastrado";
        }
    }

}
