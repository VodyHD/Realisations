<?php
  class ControlAffPart extends CI_Controller {
    public function __construct(){
      parent::__construct();
      $this->load->library('form_validation');
    }
    public function index() {
      $this->load->model('doodle');
          $conn = $this->doodle->recherche($this->session->userdata('cleparticipant'));
          $dates = $this->doodle->getDate();
          $jour = $this->doodle->getJour();
          $this->load->view('participation',array("sondages"=>$conn,
                                                "dates"=>$dates,
                                                "jours"=>$jour,
                                                "participant"=>$this->session->userdata('part'))); 
          if(isset($_GET['particip'])){
              $k=0;
              $m=0;
              while(isset($dates[$k])){
                while(isset($_GET['choice_'.($k).($m)])){
                  $bu = $dates[$m];
                  $ba = $jour[$k];
                  $this->doodle->addParticipant(array("cle"=>$this->session->userdata('cleparticipant'),
                                                      "nom"=>$this->session->userdata('part'),
                                                      "jour"=>$ba['jour'],
                                                      "heure"=>$bu['heure']));
                  $m++;
                }
                $m++;
                $k++;
              }
              redirect('/ControlAffPart/suite');
            }
            
          }
          public function suite(){
            $this->session->unset_userdata('cleparticipant');
            $this->session->unset_userdata('part');
            redirect('/Control/');
          }
       }
  ?>
