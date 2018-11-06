<!DOCTYPE html>                                                                                    
<html lang="fr">
  <head>
    <meta charset="UTF-8" />
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('style')?>">
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('bootstrap.min')?>">
    <title>SwimmingPoll</title>
  </head>
  <header>
            <br>
        <div class="row w-100">
          <div class="col-md-4">
            <a class="lien" href="/~quernec/PHP/Project_php/"><img class="mx-auto d-lg-block" alt="" src="<?php echo img_url('presentation200.png');?>"/></a>
          </div>
          <div class="col-md-4">
            <?php
             $blabla = $this->session->user;
             $truc = $blabla[0];
             echo "<br><p>Vous êtes connecté en tant que : ".$truc['login']."</p>";?>
          </div>
          <div class="col-md-4">
            <a class="lien" href="/~quernec/PHP/Project_php/index.php/ControlSondage">Créer un sondage</a>
            <b style="color:#A6E6FA";>&nbsp;&nbsp;|&nbsp;&nbsp;</b>
            <a class="lien" href="/~quernec/PHP/Project_php/index.php/Control/deconnexion">Deconnexion</a>
          </div>
      </header>
  <body>
    <div class="mr-auto ml-auto w-75">
      <div class="row" style="margin-bottom:4%;margin-top:3%;">
        <div class="ml-auto mr-auto">
          <h1>Vos Sondages</h1>
        </div>
      </div>
        <table class="table table-bordered table-striped table-dark">
          <thead class="">
            <tr>
              <th scope="col">
                Etat
              </th>
              <th scope="col">
                Titre
              </th>
              <th scope="col">
                Lieu
              </th>
              <th scope="col">
                Descriptif
              </th>
              <th scope="col">
                Participants
              </th>
              <th scope="col">
                Cle
              </th>
              <th scope="col">
                Date
              </th>
            </tr>
          </thead>
          <tbody>
            <?php
            if(isset($dates)){
              $this->load->model('doodle');
              foreach($sondages as $key){?>
              <tr>
                <td>
                  <?php if($key['status']=="true"){echo "Ouvert <a href='/~quernec/PHP/Project_php/index.php/Control/changeStatus/".$key['cle']."'><img src='".img_url('Red_Cross.png')."' alt=''/></a>";}
                        else{echo "Fermé";} ?>
                </td>
                <td>
                  <?php echo "".$key['titre'] ?>
                </td>
                <td>
                  <?php echo "".$key['lieu'] ?>
                </td>
                <td>
                  <?php echo "".$key['descriptif'] ?>
                </td>
                <td>
                  <?php echo "".($this->doodle->getNbSondages($key['cle'])) ?>
                </td>
                <td>
                  <?php echo "".$key['cle'] ?>
                </td>
                <td class="w-50">
                  <table class="w-100">
                    <thead>
                      <tr>
                        <th scope="col">
                          Jour
                        </th>
                        <th scope="col">
                          Heure
                        </th>
                        <th scope="col">
                          Votes
                        </th>
                      </tr>
                    </thead>
                    <tbody>
                      <?php
                      $p='';
                      $v=1;
                     
                      for($k=0;isset($jours[$k]);$k++){
                        $hu = $jours[$k];
                        if($hu['cle']==$key['cle']){
                          echo "<tr>";
                            echo "<td>";
                              echo "<div>Jour ".($v)." : ".$hu['jour']."</div>";
                            echo "</td>";
                            echo "<td>";
                             $controle = 1;
                              for($bb=0;isset($dates[$bb]);$bb++){
                                $hi = $dates[$bb];
                                if($hi['cle']==$hu['cle'] && $hi['jour']==$hu['jour']){
                                  echo "<div>Heure ".($controle)." : ".$hi['heure']."</div>";
                                  $controle++;
                                }
                              }
                            echo "</td>";
                            echo "<td>";
                            $this->load->model('doodle');
                              for($bb=0;isset($dates[$bb]);$bb++){
                                $hi = $dates[$bb];
                                if($hi['cle']==$hu['cle'] && $hi['jour']==$hu['jour']){
                                  echo "<div>".($this->doodle->getNbVotes($key['cle'],$hu['jour'],$hi['heure']))."</div>";
                                }
                              }
                            echo "</td>";
                          echo "</tr>";
                          $v++;
                        }
                      }
                      ?>
                    </tbody>
                  </table>
                </td>
              </tr>
              <?php
      }
    }
        ?>
          </tbody>
        </table>
      </div>
  </body>
</html>