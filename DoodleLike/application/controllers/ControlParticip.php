<?php
	class ControlParticip extends CI_Controller {
    public function __construct(){
      parent::__construct();
      $this->load->library('form_validation');
    }
		public function index() {
      $this->form_validation->set_rules('nomparticip','Participant','required');
      if(!isset($_GET['nomparticip'])){
        $this->load->view('authentificationPartage');
      }else{
            $this->load->model('doodle');
            $yu = $this->doodle->getParticipant($this->session->userdata('cleparticipant'),$_GET['nomparticip']);
            if(count($yu)==0){
              echo "<p>BOLOSS</p>";
              $this->session->set_userdata('part',$_GET['nomparticip']);
              redirect('/ControlAffPart/');
            }else{?>
              <script type="text/javascript">
                alert("Vous avez déja participer avec ce nom");
              </script>
              <?php $this->load->view('authentificationPartage');
              echo "<p>".
              count($yu)."</p>";
            }
          }
       }

      }
  ?>
