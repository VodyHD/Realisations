<?php
 if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Doodle extends CI_Model {
  public function connexion() {
    $conn = $this->input->post();
    $sql = $this->db->select("login,passwd")
          ->from("User")
          ->where(array("login" => $conn['login']))
          ->get()
          ->result_array();
    $sql[1] = $conn['passwd'];
    return $sql;
    /*if(sizeof($sql)==1){
      if (password_verify($conn['passwd'],$sql[0]['passwd'])) {
        $this->session->set_userdata('login', $conn['login']);
        echo "<p>bien ouej</p>";
         $this->load->view('sondage');
      } else {
        echo "<p>code faux</p>";
        $data = array('login' => $conn['login']);
        $this->load->view('Main',$data);
      }
    } else {
      $data = array('login' => $conn['login']);
      echo "<p>aucun login ne correspond</p>";
      $this->load->view('Main',$data);
     }*/
  }
  /* On a besoin de cette fonction pour récupérer toutes les infos liés à un login genre E-mail
    et nom et prénom */
  public function getInfo(){
    $conn = $this->input->post();
    $sql = $this->db->select("*")
          ->from("User")
          ->where(array("login" => $conn['login']))
          ->get()
          ->result_array();
    return $sql;
  }
  public function getNbVotes($cle,$jour,$heure){
    $sql = $this->db->select("*")
            ->from("Participant")
            ->where(array("cle"=>$cle,
                          "jour"=>$jour,
                          "heure"=>$heure))
            ->get()
            ->result_array();
    return count($sql);
  }
  public function addParticipant($arr){
    $this->db->insert('Participant',$arr);
    return $this->db->affected_rows();
  }
  public function getParticipant($cle,$nom){
    $sql = $this->db->select("nom")
          ->from("Participant")
          ->where(array("cle" => $cle,
                        "nom"=>$nom))
          ->get()
          ->result_array();
    return $sql;
  }
  public function creation(){
    $conn = $this->input->post();
    if ($conn['mdp'] == $conn['mdp1']) {
      $conn['mdp'] = password_hash($conn['mdp'],PASSWORD_DEFAULT);
      $this->session->set_userdata('login', $conn['login']);
      $tab = array(
           'login'=>$conn['login'],
            'passwd'=>$conn['mdp'],
            'mail'=>$conn['mail'],
            'nom'=>$conn['nom'],
            'prenom'=>$conn['prenom']);
    $this->db->insert('User', $tab);
    }
    return $this->db->affected_rows();
  }
  public function getNbHeureMax($i){
    $sql = $this->db->select("*")
                    ->from("date")
                    ->where(array("jour"=>$i));
    return $this->db->count_all_results();
  }
  public function getMySondage(){
    $blabla = $this->session->user;
    $truc = $blabla[0];
    $sql = $this->db->select("*")
                ->from("Sondage")
                ->where(array("createur" => $truc['login']))
                ->get()
                ->result_array();
    return $sql;
  }
  public function getJour(){
    $blabla = $this->session->user;
    $truc = $blabla[0];
    $sql = $this->db->distinct()
                ->select("jour,cle")
                ->from("Date")
                ->get()
                ->result_array();
    return $sql;
  }
  public function getNbSondages($cle){
    $sql = $this->db->distinct()
                    ->select("nom")
                    ->from("Participant")
                    ->where(array("cle"=>$cle))
                    ->get()
                    ->result_array();
    return count($sql);
  }
  public function alterStatus($cle){
    $this->db->set("status","false")
              ->where(array("cle"=>$cle))
              ->update("Sondage");
  }
  public function getDate(){
    $blabla = $this->session->user;
    $truc = $blabla[0];
    $sql1 = $this->db->select("*")
    ->from("Date")
    ->get()
    ->result_array();
    return $sql1;
  }
  
  public function creation_sondage() { /*Cle à 8 chiffres*/
    $char = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQSTUVWXYZ0123456789';
    $cle = substr(str_shuffle($char), 0, 8);
    $this->session->set_userdata('key',$cle);
    $conn = $this->input->post();
    $test = $this->session->user;
    $log = $test[0];
    $tab = array(
          'titre'=>$conn['titre'],
          'lieu'=>$conn['lieu'],
          'descriptif'=>$conn['desc'],
          'createur'=>$log['login'],
          'cle'=>$cle);
    $this->db->insert('Sondage', $tab);
    for($m=1;$m<=$this->session->userdata('compteurDate');$m++){
      for($i=1;$i<=$this->session->userdata('compteur_'.$m);$i++){
        $tab1 = array(
              'cle'=>$cle,
              'jour'=>$conn['date_'.$m],
              'heure'=>$conn['heure_'.$m.$i]);
        $this->db->insert('Date', $tab1);
      }
    }
    return $this->db->affected_rows();
   }
   public function recherche($val){
    $sql = $this->db->select("*")
                ->from("Sondage")
                ->where(array("cle"=>$val))
                ->get()
                ->result_array();
    return $sql;
   }
   public function rechercheStatus($val){
    $sql = $this->db->select("status")
                ->from("Sondage")
                ->where(array("cle"=>$val))
                ->get()
                ->result_array();
    return $sql;
   }
}
?>