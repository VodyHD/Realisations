<?php
	class ControlMail extends CI_Controller {
    public function __construct(){
      parent::__construct();
      $this->load->library('form_validation');
    }
		public function index() {
      $this->form_validation->set_rules('sendmail','Titre','required');
      if (isset($_POST['sendmail'])){
        $conn = $this->input->post();
        $to = '';
        for($o=1;$o<=$this->session->userdata('compteurMail');$o++){
          $to = $to.','.$conn['inputmail_'.$o];
        }

         // Sujet
         $subject = 'Participation';
         $blabla = $this->session->user;
          $truc = $blabla[0];
         // message
         $message = '
         <html>
          <head>
           <title>Participation</title>
          </head>
          <body>
           <p>Bonjour,<br></p>
           <p>Vous avez reçu une invitation de '.$truc['login'].' pour participer  à un sondage sur le site SwimmingPoll, veuillez accéder à cet url : <a href="dwarves.iut-fbleau.fr/~baaziz/TPPHP/project/Project_php/">dwarves.iut-fbleau.fr/~baaziz/TPPHP/project/Project_php/</a>et y ajouter ceci : ?cle='.$this->session->userdata('key').'</p>
          </body>
         </html>
         ';

         $headers[] = 'MIME-Version: 1.0';
         $headers[] = 'Content-type: text/html; charset=iso-8859-1';

         $b = mail($to, $subject, $message, implode("\r\n", $headers));
         if(!$b){
          echo "<p>Pas bon</p>";
         }else{
          redirect('Control/');
         }
      }else{
        if(isset($_POST['ajoutqqn'])){
          $pff = $this->input->post();
          $i=$this->session->userdata('compteurMail');
          for($p=1;$p<=$i;$p++){
            $this->session->set_userdata('inputmail_'.$p,$pff['inputmail_'.$p]);
          }
          $i++;
          $this->session->set_userdata('compteurMail',$i);
        }else if(isset($_POST['enleveqqn'])){
          $i=$this->session->userdata('compteurMail');
          if($i>1){
            $pff = $this->input->post();
            for($p=1;$p<=$i;$p++){
              $this->session->set_userdata('inputmail_'.$p,$pff['inputmail_'.$p]);
            }
            $this->session->unset_userdata('inputmail_'.$i);
            $i--;
            $this->session->set_userdata('compteurMail',$i);
          }
        }
      }
      $this->load->view('Mail');

 		}
    public function addMail(){
      $this->load->view('Mail');
    }
	}
?>
