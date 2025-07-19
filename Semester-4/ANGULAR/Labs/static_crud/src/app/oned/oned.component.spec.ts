import { ComponentFixture, TestBed } from '@angular/core/testing';

import { OnedComponent } from './oned.component';

describe('OnedComponent', () => {
  let component: OnedComponent;
  let fixture: ComponentFixture<OnedComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [OnedComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(OnedComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
