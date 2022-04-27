import cypher_control
import pygtk
pygtk.require('2.0')
import gtk



def put_images(fixed):

    image = gtk.image_new_from_file('Imagens\Banner.jpg')
    fixed.attach(image, 0, 120, 0, 25)
    image.show()

    image = gtk.image_new_from_file('Imagens\\arquivo.jpg')
    fixed.attach(image, 2, 12, 23, 43)
    image.show()

    image = gtk.image_new_from_file('Imagens\perfil.png')
    fixed.attach(image, 63, 70, 23, 40)
    image.show()

def put_buttons(self, fixed, window, arq, cifrar, decifrar):

    self.button = gtk.Button()
    self.button.props.relief = gtk.RELIEF_NONE
    self.button.connect("clicked", arq, window)
    self.button.set_usize(166, 40)
    self.image = gtk.image_new_from_file('Imagens\Selecionar.jpg')
    self.button.add(self.image)
    self.image.show()
    fixed.attach(self.button, 51, 72, 70, 80)
    self.button.show()

    self.button = gtk.Button()
    self.button.props.relief = gtk.RELIEF_NONE
    self.button.connect("clicked", cifrar, fixed, self.button)
    self.button.set_usize(250, 60)
    self.image = gtk.image_new_from_file('Imagens\Criptografar.jpg')
    self.button.add(self.image)
    self.image.show()
    fixed.attach(self.button, 51, 72, 80, 90)
    self.button.show()

    self.button = gtk.Button()
    self.button.props.relief = gtk.RELIEF_NONE
    self.button.connect("clicked", decifrar, fixed, self.button)
    self.button.set_usize(166, 40)
    self.image = gtk.image_new_from_file('Imagens\Descriptografar.jpg')
    self.button.add(self.image)
    self.image.show()
    fixed.attach(self.button, 51, 72, 90, 100)
    self.button.show()


    self.button = gtk.Button()
    self.button.props.relief = gtk.RELIEF_NONE
    self.button.connect("clicked", cypher_control.troca_pasta, fixed)
    self.button.set_usize(166, 40)
    self.image = gtk.image_new_from_file('Imagens\\troca.jpg')
    self.button.add(self.image)
    self.image.show()
    fixed.attach(self.button, 63, 84, 50, 60)
    self.button.show()


    self.button = gtk.Button()
    self.button.props.relief = gtk.RELIEF_NONE
    self.button.connect("clicked", cypher_control.compartilha, fixed)
    self.button.set_usize(166, 40)
    self.image = gtk.image_new_from_file('Imagens\Compartilhar.jpg')
    self.button.add(self.image)
    self.image.show()
    fixed.attach(self.button, 3, 24, 50, 60)
    self.button.show()

def put_labels(self, fixed, radioresponse, label_nome, label_tamanho, label_status, scrolled, scrolled2, radioresponse_aux):

    self.label = gtk.Label("Nome do arquivo : ")
    fixed.attach(self.label, 11, 30, 25, 30)
    self.label.show()
    fixed.attach(label_nome, 30, 58, 25, 30)
    label_nome.show()

    self.label = gtk.Label("Arquivo selecionado")
    fixed.attach(self.label, 11, 30, 20, 25)
    self.label.show()

    self.label = gtk.Label("Tamanho do arquivo : ")
    fixed.attach(self.label, 13, 30, 30, 35)
    self.label.show()
    fixed.attach(label_tamanho, 30, 58, 30, 35)
    label_tamanho.show()

    self.label = gtk.Label("Status de criptografia : ")
    fixed.attach(self.label, 13, 30, 35, 40)
    self.label.show()
    fixed.attach(label_status, 30, 58, 35, 40)
    label_status.show()

    self.label = gtk.Label("Arquivos Criptografados")
    fixed.attach(self.label, 0, 13, 65, 70)
    self.label.show()


    self.label = gtk.Label("Arquivos Descriptografados")
    fixed.attach(self.label, 73, 89, 65, 70)
    self.label.show()

    self.label = gtk.Label("Nome do usuario : ")
    fixed.attach(self.label, 71, 90, 25, 30)
    self.label.show()

    self.label = gtk.Label("Email :")
    fixed.attach(self.label, 71, 84, 30, 35)
    self.label.show()

    self.label = gtk.Label("Pasta 'decifrados' :")
    fixed.attach(self.label, 71, 89, 35, 40)
    self.label.show()

    cypher_control.put_label(self, fixed)

    fixed.attach(label_tamanho, 30, 58, 30, 35)
    label_tamanho.show()

    self.separator = gtk.HSeparator()
    fixed.attach(self.separator, 0, 120, 62, 63)
    self.separator.show()


    self.separator = gtk.VSeparator()
    fixed.attach(self.separator, 61, 62, 25, 62)
    self.separator.show()

    radioresponse(fixed, scrolled)
    radioresponse_aux(fixed, scrolled2)

def controle_cadastro(self):

    self.cadastro = gtk.Window( )
    self.cadastro.set_position(gtk.WIN_POS_CENTER)
    self.cadastro.set_size_request(600, 500)
    self.cadastro.set_title("Cadastro")

    self.fixed = gtk.Table(100, 100, True)
    self.cadastro.add(self.fixed)

    self.label = gtk.Label("Nome completo :")
    self.label.set_alignment(0, 0.5)
    self.fixed.attach(self.label, 1, 20, 0, 10)

    self.label = gtk.Label("Email :")
    self.label.set_alignment(0,0.5)
    self.fixed.attach(self.label, 1, 20, 10, 20)

    self.label = gtk.Label("Senha :")
    self.label.set_alignment(0, 0.5)
    self.fixed.attach(self.label, 1, 20, 20, 30)

    self.label = gtk.Label("Confirmar senha :")
    self.label.set_alignment(0, 0.5)
    self.fixed.attach(self.label, 1, 20, 30, 40)

    self.label = gtk.Label("Palavra chave (senha) :")
    self.label.set_alignment(0, 0.5)
    self.fixed.attach(self.label, 1, 20, 40, 50)

    self.label = gtk.Label("Data de nascimento :")
    self.label.set_alignment(0, 0.5)
    self.fixed.attach(self.label, 1, 20, 50, 60)

    self.nome = gtk.Entry(max=0)
    self.fixed.attach(self.nome, 21, 98, 0, 10)

    self.email = gtk.Entry(max=0)
    self.fixed.attach(self.email, 21, 98, 10, 20)

    self.senha = gtk.Entry(max=0)
    self.senha.set_visibility(False)
    self.senha.set_invisible_char("*")
    self.fixed.attach( self.senha, 21, 98, 20, 30)

    self.confirmar = gtk.Entry(max=0)
    self.confirmar.set_visibility(False)
    self.confirmar.set_invisible_char("*")
    self.fixed.attach(self.confirmar, 21, 98, 30, 40)

    self.palavra = gtk.Entry(max=0)
    self.fixed.attach(self.palavra, 21, 98, 40, 50)

    self.data = gtk.Entry(max=0)
    self.fixed.attach(self.data, 21, 98, 50, 60)

    self.button = gtk.Button("Cadastrar-se !")
    self.button.connect("clicked", cypher_control.cadastrar_novo_user, self.cadastro, self.fixed, self.nome, self.email, self.senha, self.confirmar, self.palavra, self.data)
    self.fixed.attach(self.button, 0, 100, 90, 100)

    self.cadastro.show_all()


def controle_esquecisenha(self):

    cadastro = gtk.Window( )
    cadastro.set_position(gtk.WIN_POS_CENTER)
    cadastro.set_size_request(400, 100)
    cadastro.set_title("Recuperar senha")

    fixed = gtk.Table(30, 30, True)
    cadastro.add(fixed)

    label = gtk.Label("Nome de usuario : ")
    label.set_alignment(0, 0.5)
    fixed.attach(label, 1, 6, 0, 10)

    entry = gtk.Entry(max=0)
    fixed.attach(entry, 8, 28, 0, 10)

    button = gtk.Button("Recuperar Senha !")
    button.connect("clicked", cypher_control.esqueci_minha_senha_aux, cadastro, entry)
    fixed.attach(button, 0, 30, 25, 30)

    cadastro.show_all()