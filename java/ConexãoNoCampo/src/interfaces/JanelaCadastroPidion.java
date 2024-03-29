package interfaces;
import controle.ControladorCadastroPidion;
import entidades.Pidion;
import entidades.Visão;
import java.util.Vector;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JOptionPane;

public class JanelaCadastroPidion extends javax.swing.JFrame {
   ControladorCadastroPidion controlador;
   Vector<Visão<String>> lista_pidion ;

    public JanelaCadastroPidion(ControladorCadastroPidion controlador) {
        this.controlador = controlador;
        lista_pidion = Pidion.getVisões();
        initComponents();
        jTextID.setText("0");
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanelNome = new javax.swing.JPanel();
        jTextN_Patrimonio = new javax.swing.JTextField();
        jLabelN_Patrimonio = new javax.swing.JLabel();
        jLabelN_Bunge = new javax.swing.JLabel();
        jTextID = new javax.swing.JTextField();
        jTextN_Bunge = new javax.swing.JTextField();
        jPanelProfissão = new javax.swing.JPanel();
        jTextN_Patrimonio_Impressora = new javax.swing.JTextField();
        jLabelN_Patrimonio_Impressora = new javax.swing.JLabel();
        jLabelModelo_Impressora = new javax.swing.JLabel();
        jLabelSérie_Impressora = new javax.swing.JLabel();
        jTextSérie_Impressora = new javax.swing.JTextField();
        jComboBox2 = new javax.swing.JComboBox<>();
        jPanelSenha1 = new javax.swing.JPanel();
        jLabelPesquisar = new javax.swing.JLabel();
        jButtonBuscar = new javax.swing.JButton();
        jButtonAlterar = new javax.swing.JButton();
        jButtonRemover = new javax.swing.JButton();
        jButtonInserir = new javax.swing.JButton();
        jComboBox1 = new javax.swing.JComboBox<>();
        jButtonLimpar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Cadastro de Pidion");
        setLocation(new java.awt.Point(0, 0));
        setLocationByPlatform(true);
        setMaximumSize(new java.awt.Dimension(710, 350));
        setMinimumSize(new java.awt.Dimension(710, 350));
        setPreferredSize(new java.awt.Dimension(710, 350));
        setResizable(false);
        setSize(new java.awt.Dimension(710, 350));
        setType(java.awt.Window.Type.UTILITY);

        jTextN_Patrimonio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextN_PatrimonioActionPerformed(evt);
            }
        });

        jLabelN_Patrimonio.setText("Numero Patrimônio Pidion");

        jLabelN_Bunge.setText("Numero Bunge");

        jTextID.setEditable(false);
        jTextID.setToolTipText("");

        jTextN_Bunge.setToolTipText("");
        jTextN_Bunge.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextN_BungeActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanelNomeLayout = new javax.swing.GroupLayout(jPanelNome);
        jPanelNome.setLayout(jPanelNomeLayout);
        jPanelNomeLayout.setHorizontalGroup(
            jPanelNomeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelNomeLayout.createSequentialGroup()
                .addGap(28, 28, 28)
                .addGroup(jPanelNomeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jTextN_Patrimonio, javax.swing.GroupLayout.PREFERRED_SIZE, 295, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabelN_Patrimonio)
                    .addComponent(jTextID, javax.swing.GroupLayout.PREFERRED_SIZE, 44, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(26, 26, 26)
                .addGroup(jPanelNomeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabelN_Bunge)
                    .addComponent(jTextN_Bunge, javax.swing.GroupLayout.PREFERRED_SIZE, 306, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(18, Short.MAX_VALUE))
        );
        jPanelNomeLayout.setVerticalGroup(
            jPanelNomeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanelNomeLayout.createSequentialGroup()
                .addComponent(jTextID, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 12, Short.MAX_VALUE)
                .addGroup(jPanelNomeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabelN_Bunge)
                    .addComponent(jLabelN_Patrimonio))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanelNomeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextN_Patrimonio, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextN_Bunge, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(25, 25, 25))
        );

        jPanelProfissão.setMaximumSize(new java.awt.Dimension(500, 500));
        jPanelProfissão.setMinimumSize(new java.awt.Dimension(500, 500));
        jPanelProfissão.setName(""); // NOI18N

        jTextN_Patrimonio_Impressora.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextN_Patrimonio_ImpressoraActionPerformed(evt);
            }
        });

        jLabelN_Patrimonio_Impressora.setText("Numero do Patrimônio Impressora");

        jLabelModelo_Impressora.setText("Modelo Impressora");

        jLabelSérie_Impressora.setText("Série da Impressora");

        jComboBox2.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "HP OfficeJet 100", "HP OfficeJet 200" }));

        javax.swing.GroupLayout jPanelProfissãoLayout = new javax.swing.GroupLayout(jPanelProfissão);
        jPanelProfissão.setLayout(jPanelProfissãoLayout);
        jPanelProfissãoLayout.setHorizontalGroup(
            jPanelProfissãoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelProfissãoLayout.createSequentialGroup()
                .addGap(28, 28, 28)
                .addGroup(jPanelProfissãoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jTextN_Patrimonio_Impressora, javax.swing.GroupLayout.PREFERRED_SIZE, 169, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabelN_Patrimonio_Impressora, javax.swing.GroupLayout.PREFERRED_SIZE, 170, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(22, 22, 22)
                .addGroup(jPanelProfissãoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabelModelo_Impressora)
                    .addComponent(jComboBox2, javax.swing.GroupLayout.PREFERRED_SIZE, 226, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanelProfissãoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabelSérie_Impressora)
                    .addComponent(jTextSérie_Impressora, javax.swing.GroupLayout.PREFERRED_SIZE, 185, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(24, Short.MAX_VALUE))
        );
        jPanelProfissãoLayout.setVerticalGroup(
            jPanelProfissãoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanelProfissãoLayout.createSequentialGroup()
                .addGroup(jPanelProfissãoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabelN_Patrimonio_Impressora)
                    .addComponent(jLabelModelo_Impressora)
                    .addComponent(jLabelSérie_Impressora))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanelProfissãoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jTextN_Patrimonio_Impressora, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextSérie_Impressora, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jComboBox2, javax.swing.GroupLayout.Alignment.TRAILING))
                .addGap(448, 448, 448))
        );

        jLabelPesquisar.setText("Consultar");

        jButtonBuscar.setText("Buscar");
        jButtonBuscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonBuscarActionPerformed(evt);
            }
        });

        jButtonAlterar.setText("Alterar");
        jButtonAlterar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonAlterarActionPerformed(evt);
            }
        });

        jButtonRemover.setText("Remover");
        jButtonRemover.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonRemoverActionPerformed(evt);
            }
        });

        jButtonInserir.setText("Inserir");
        jButtonInserir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonInserirActionPerformed(evt);
            }
        });

        jComboBox1.setModel(new DefaultComboBoxModel (lista_pidion));

        jButtonLimpar.setText("Limpar");
        jButtonLimpar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonLimparActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanelSenha1Layout = new javax.swing.GroupLayout(jPanelSenha1);
        jPanelSenha1.setLayout(jPanelSenha1Layout);
        jPanelSenha1Layout.setHorizontalGroup(
            jPanelSenha1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelSenha1Layout.createSequentialGroup()
                .addGap(28, 28, 28)
                .addGroup(jPanelSenha1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabelPesquisar)
                    .addGroup(jPanelSenha1Layout.createSequentialGroup()
                        .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, 227, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonBuscar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jButtonAlterar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonRemover)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonInserir)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonLimpar)))
                .addContainerGap(22, Short.MAX_VALUE))
        );
        jPanelSenha1Layout.setVerticalGroup(
            jPanelSenha1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelSenha1Layout.createSequentialGroup()
                .addComponent(jLabelPesquisar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanelSenha1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE, false)
                    .addComponent(jButtonBuscar)
                    .addComponent(jButtonAlterar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButtonRemover, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButtonInserir, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButtonLimpar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(23, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(27, 27, 27)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanelProfissão, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jPanelNome, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jPanelSenha1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanelSenha1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanelNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jPanelProfissão, javax.swing.GroupLayout.PREFERRED_SIZE, 71, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(61, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonBuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonBuscarActionPerformed
        Pidion pidion = null;
        String mensagem_erro = null;
        String Pidion_busca = String.valueOf(jComboBox1.getSelectedItem());
        String[] splitted = Pidion_busca.split("-");
        Pidion_busca = splitted[0];
        String Comp = "Selecione o Pidion";
        if(!Pidion_busca.equals(Comp)){
            pidion=Pidion.buscaPidion(Pidion_busca);   
            if(pidion == null){
                mensagem_erro = "Pidion não cadastrado";
            }
        }else{
            mensagem_erro="Selecione algum pidion";
            jTextID.setText(String.valueOf(0));
            jTextN_Patrimonio.setText("");
            jTextN_Bunge.setText("");
            jTextN_Patrimonio_Impressora.setText("");
            jTextSérie_Impressora.setText("");         
        }
        if(mensagem_erro==null){
            jTextID.setText(String.valueOf(pidion.getID()));
            jTextN_Patrimonio.setText(String.valueOf(pidion.getNum_Patrimônio()));
            jTextN_Bunge.setText(String.valueOf(pidion.getNum_Bunge()));
            jTextN_Patrimonio_Impressora.setText(String.valueOf(pidion.getNum_Patrimônio_Impressora()));
            jComboBox2.setSelectedItem(pidion.getModelo());
            jTextSérie_Impressora.setText(pidion.getSérieImpressora());            
        }else{
            jTextID.setText(String.valueOf(0));
            jTextN_Patrimonio.setText("");
            jTextN_Bunge.setText("");
            jTextN_Patrimonio_Impressora.setText("");
            jTextSérie_Impressora.setText("");            
            JOptionPane.showMessageDialog(this,mensagem_erro,"ERRO",JOptionPane.ERROR_MESSAGE);
        }
    }//GEN-LAST:event_jButtonBuscarActionPerformed

    private void jButtonInserirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonInserirActionPerformed
        Pidion pidion = obterPidionInformado();
        String menssagem_erro = null;
        if (pidion != null){
            menssagem_erro = controlador.inserirPidion(pidion);
        }else{
            menssagem_erro = "Algum campo não foi preenchido";
        }
        if (menssagem_erro == null){
            menssagem_erro = "Pidion cadastrado com sucesso!";
            lista_pidion.add(pidion.getVisão());             
            jComboBox1.setSelectedIndex(lista_pidion.size()-1);
            JOptionPane.showMessageDialog(this, menssagem_erro,"Sucesso",JOptionPane.INFORMATION_MESSAGE);
        }else{
            JOptionPane.showMessageDialog(this,menssagem_erro,"ERRO",JOptionPane.ERROR_MESSAGE);
        }
    }//GEN-LAST:event_jButtonInserirActionPerformed

    private void jButtonAlterarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonAlterarActionPerformed
        Visão<String> visão = visão = (Visão<String>) jComboBox1.getSelectedItem();
        
        Pidion pidion = obterPidionInformado();
        String menssagem_erro = null;
        if (pidion != null){
            menssagem_erro = controlador.alterarPidion(pidion);
        }else{
            menssagem_erro = "Algum campo não foi preenchido";
        }
        if (menssagem_erro == null){
            menssagem_erro = "Pidion alterado com sucesso!";
            
            lista_pidion.remove(visão);      
            lista_pidion.add(pidion.getVisão());             
            jComboBox1.setSelectedIndex(lista_pidion.size()-1);
            
            JOptionPane.showMessageDialog(this, menssagem_erro,"Sucesso",JOptionPane.INFORMATION_MESSAGE);
        }else{
            JOptionPane.showMessageDialog(this,menssagem_erro,"ERRO",JOptionPane.ERROR_MESSAGE);
        }
    }//GEN-LAST:event_jButtonAlterarActionPerformed

    private void jButtonRemoverActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonRemoverActionPerformed
        Visão<String> visão = (Visão<String>) jComboBox1.getSelectedItem ();
        Pidion pidion = obterPidionInformado();
        String menssagem_erro = null;
        if (pidion != null){
            menssagem_erro = controlador.removerPidion(pidion);
        }else{
            menssagem_erro = "Algum campo não foi preenchido";
        }
        if (menssagem_erro == null){
            menssagem_erro = "Pidion removido com sucesso!";
            jTextID.setText(String.valueOf(0));
            jTextN_Patrimonio.setText("");
            jTextN_Bunge.setText("");
            jTextN_Patrimonio_Impressora.setText("");
            jTextSérie_Impressora.setText(""); 
            lista_pidion.remove(visão);      
            if (lista_pidion.size() >= 1)  jComboBox1.setSelectedIndex(0);            
            else jComboBox1.setSelectedIndex(-1);  
            JOptionPane.showMessageDialog(this, menssagem_erro,"Sucesso",JOptionPane.INFORMATION_MESSAGE);
            
        }else{
            JOptionPane.showMessageDialog(this,menssagem_erro,"ERRO",JOptionPane.ERROR_MESSAGE);
        }
    }//GEN-LAST:event_jButtonRemoverActionPerformed

    private void jTextN_PatrimonioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextN_PatrimonioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextN_PatrimonioActionPerformed

    private void jTextN_Patrimonio_ImpressoraActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextN_Patrimonio_ImpressoraActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextN_Patrimonio_ImpressoraActionPerformed

    private void jTextN_BungeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextN_BungeActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextN_BungeActionPerformed

    private void jButtonLimparActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonLimparActionPerformed
        jTextID.setText(String.valueOf(0));
            jTextN_Patrimonio.setText("");
            jTextN_Bunge.setText("");
            jTextN_Patrimonio_Impressora.setText("");
            jTextSérie_Impressora.setText("");     
    }//GEN-LAST:event_jButtonLimparActionPerformed

    private Pidion obterPidionInformado(){

        int id = Integer.parseInt(jTextID.getText());
        String N_Patrimonio = jTextN_Patrimonio.getText();
        if (N_Patrimonio.isEmpty()) return null;
        
        String N_Bunge = jTextN_Bunge.getText();
        if (N_Bunge.isEmpty()) return null;
        
        String N_Patrimonio_Impressora = jTextN_Patrimonio_Impressora.getText();
        if (N_Patrimonio_Impressora.isEmpty()) return null;
        
        int situação = jComboBox2.getSelectedIndex();
        String Modelo_Impressora=null;
        if (situação == 0){
            Modelo_Impressora = "HP OfficeJet 100";
        }else{
              Modelo_Impressora = "HP OfficeJet 200";
        }

        String Série_Impressora = jTextSérie_Impressora.getText();
        if (Série_Impressora.isEmpty()) return null;
        
        return new Pidion(id,Integer.valueOf(N_Patrimonio),Integer.valueOf(N_Bunge),Integer.valueOf(N_Patrimonio_Impressora),Modelo_Impressora,Série_Impressora);
   
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(JanelaCadastroPidion.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(JanelaCadastroPidion.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(JanelaCadastroPidion.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(JanelaCadastroPidion.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>


    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonAlterar;
    private javax.swing.JButton jButtonBuscar;
    private javax.swing.JButton jButtonInserir;
    private javax.swing.JButton jButtonLimpar;
    private javax.swing.JButton jButtonRemover;
    private javax.swing.JComboBox<String> jComboBox1;
    private javax.swing.JComboBox<String> jComboBox2;
    private javax.swing.JLabel jLabelModelo_Impressora;
    private javax.swing.JLabel jLabelN_Bunge;
    private javax.swing.JLabel jLabelN_Patrimonio;
    private javax.swing.JLabel jLabelN_Patrimonio_Impressora;
    private javax.swing.JLabel jLabelPesquisar;
    private javax.swing.JLabel jLabelSérie_Impressora;
    private javax.swing.JPanel jPanelNome;
    private javax.swing.JPanel jPanelProfissão;
    private javax.swing.JPanel jPanelSenha1;
    private javax.swing.JTextField jTextID;
    private javax.swing.JTextField jTextN_Bunge;
    private javax.swing.JTextField jTextN_Patrimonio;
    private javax.swing.JTextField jTextN_Patrimonio_Impressora;
    private javax.swing.JTextField jTextSérie_Impressora;
    // End of variables declaration//GEN-END:variables
}
