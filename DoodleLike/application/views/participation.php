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
      </header>
  <body>
    <div class="mr-auto ml-auto w-75">
      <div class="row" style="margin-bottom:4%;margin-top:3%;">
        <div class="ml-auto mr-auto">
          <h1>Veuillez Participer</h1>
        </div>
      </div>
      <div class="w-100">
        <form method="GET">
            <table class="table table-bordered table-striped table-dark">
              <thead class="">
                <tr>
                  <th scope="col">
                    Créateur
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
                  $key=$sondages[0];?>
                  <tr>
                    <td>
                      <?php echo "".$key['createur'] ?>
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
                      <?php echo "".$key['cle'] ?>
                    </td>
                    <td>
                      <table>
                        <thead>
                          <tr>
                            <th scope="col">
                              Jour
                            </th>
                            <th scope="col">
                              Heure
                            </th>
                            <th scope="col">
                              Votre choix
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
                                  $controle=1;
                                echo "</td>";
                                echo "<td>";
                                for($bb=0;isset($dates[$bb]);$bb++){
                                    $hi = $dates[$bb];
                                    if($hi['cle']==$hu['cle'] && $hi['jour']==$hu['jour']){
                                      echo "<div><input class='ml-4' type='checkbox' 
                                      name='choice_".$k.$bb."' value='blablablo'/></div>";
                                      $controle++;
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
            ?>
              </tbody>
            </table>
            <div class="row">
              <div class="mr-auto ml-auto">
                <input type="submit" class="btn btn-primary" value="Soumettre votre participation" name="particip"/>
            </div>
          </form>
        </div>
      </div>
  </body>
</html>